#include "main.h"
#include "181511057.h"
#include "181511003.h"
#include "181511044.h"
#include "181511037.h"
#include "181511028.h"
#include "181511004.h"

void tampilan_exit(double wkttotal, int score){
        setactivepage(2);
        cleardevice();

        settextstyle(DEFAULT_FONT,0,50);
        outtextxy((WINDOWS_WIDTH/2)-250,(WINDOWS_HEIGHT/2)-400, "Level Completed");
        settextstyle(DEFAULT_FONT,0,30);
        tampil_Waktu(wkttotal);
        tampil_skor_akhir(score);
        setvisualpage(2);
        getch();
}

void permainan(){
    initwindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, " ", 0, 0, true, true);

    //VARIABEL LOKAL
    infoLevel level;                        // nilai matriks map dan posisi awal sprite dalam level
    sprite player;                          // sprite player
    int score = 0;                          // Score total
    clock_t wktmulai,wktselesai;            // mencatat waktu mulai dan waktu selesai dalam satu stage
    double wkttotal;                        // mencatat durasi penyelesaian stage
    sprite bot[5];                          // sprite bot
    arrayQueue queueLubang;                 // queue untuk bata yang dilubangi
    //void* bitmap;

    level.lv = 1;
    while(level.lv <= MAX_LEVEL){
        //========= inisiasi queue untuk lubang ===========
        queueLubang = inisiasi_queue();

        //Memasukkan nilai ke semua elemen matriks dan menentukan posisi player & bot di setiap level
        level = generateStage(level.lv);

        //assign nilai dalam variabel level ke posisi sprite player
        player.pm = level.player;
        player.koor = getKoordinat(player.pm);

        //assign nilai dalam variabel level ke posisi sprite player
        for(int i = 0; i < level.jmlBot; i++){
            bot[i].pm = level.bot[i];
            bot[i].koor = getKoordinat(bot[i].pm);
        }


        //PlaySound(TEXT("audio/101-opening.wav"), NULL, SND_ASYNC);
        //============== menampilkan layar loading =================
        loading();

        //============= inisiasi page double buffering ==============
        //gambar player, bot dan map di page 0
        setactivepage(0);
        cleardevice();
        drawStage(level.arr, player.koor, bot, level.jmlBot);
        tampil_skor(score);
        tampil_level(level.lv);
        //gambar player, bot dan map di page 1
        setactivepage(1);
        cleardevice();
        drawStage(level.arr, player.koor, bot, level.jmlBot);
        tampil_skor(score);
        tampil_level(level.lv);
        //set page 0 ke active page dan page 1 ke visual page
        setactivepage(0);
        setvisualpage(1);

        //mulai permainan

        //Simpan Waktu Awal
        waktu_Awal(&wktmulai);

        while(true){
            //proses jika player mengambil koin
            if(lagiNgambilKoin(level.arr, player.pm.baris, player.pm.kolom)){
                level.arr[player.pm.baris][player.pm.kolom] = 0;
                hitung_skor(&score);
            }

            //menampilkan level
            tampil_level(level.lv);

            //mengupdate score player
            tampil_skor(score);

            //User input player.movement
            if(isFalling(level.arr, player.pm.baris, player.pm.kolom) && !isSliding(level.arr, player.pm.baris, player.pm.kolom)){
                //jika sedang jatuh maka player.movement dianggap bernilai 'S', atau sama dengan sedang bergerak ke bawah
                player.movement = 'S';
                delay(30);
            }else{
                while(kbhit()){
                    player.movement = prosesInput(toupper(getch())); //jika input player.movement tidak sesuai dengan kontrol yang sudah ditetapkan, maka assign player.movement = NULL
                }
            }

            //memproses player.movement yang diinput user
            playerMovement(level.arr, &queueLubang, &player);

            //Proses pergerakan bot[0]
            if(isFalling(level.arr,bot[0].pm.baris, bot[0].pm.kolom) && !isSliding(level.arr, bot[0].pm.baris, bot[0].pm.kolom)){
                //jika sedang jatuh maka bot[0].movement dianggap bernilai 'S', atau sama dengan sedang bergerak ke bawah
                bot[0].movement = 'S';
                delay(30);
            }else{
                bot[0].movement = 'D';
            }
            playerMovement(level.arr, &queueLubang, &bot[0]);

            //pengembalian lubang yg dibom
            if(queueLubang.Count > 0){ // apabila ada lubang di dalam map
                isi_kembali_lubang(level.arr, &queueLubang, clock());
            }

            //update posisi sprite dalam matriks
            player.pm = getPosisiMatriks(player.koor);
            for(int i = 0; i < level.jmlBot; i++){
                bot[i].pm = getPosisiMatriks(bot[i].koor);
            }

            //penggambaran bot
            drawBotArray(level.arr, bot, level.jmlBot);
            //penggambaran ulang di layar
            drawPlayerMovement(level.arr, &player);


            /*if(((player.movement != NULL) || isLagiBom(player.movement) || lagiNgambilKoin(level.arr, player.pm.baris, player.pm.kolom) || (player.urutanBom != -1)) || (bot[0].movement != NULL)){
                int area = imagesize(player.koor.X, player.koor.Y, player.koor.X + MATRIX_ELEMENT_SIZE, player.koor.Y + MATRIX_ELEMENT_SIZE);
                bitmap = malloc(area);
                getimage(player.koor.X, player.koor.Y, player.koor.X + MATRIX_ELEMENT_SIZE, player.koor.Y + MATRIX_ELEMENT_SIZE, bitmap);
                swapbuffers();
                putimage(player.koor.X, player.koor.Y, bitmap,XOR_PUT);
            }*/


            //reset animasi melempar bom jika player melakukan player.movement lain
            resetAnimasiBom(level.arr, player.pm.baris, player.pm.kolom, &player.urutanAnimasi, &player.urutanBom, player.movement, player.koor);

            //jika ada pergerakan maka swap buffer
            swapbuffers();
            //if((player.movement != NULL) || isLagiBom(player.movement) || lagiNgambilKoin(level.arr, player.pm.baris, player.pm.kolom) ||(player.urutanBom != -1)){

            //}

            //reset nilai player.movement
            player.movement = NULL;

            //cek apa semua koin sudah terkumpul
            if(!adakoin(level.arr) && (level.arr[level.pintuExit.baris][level.pintuExit.kolom] != 5))
            {
                level.arr[level.pintuExit.baris][level.pintuExit.kolom] = 5;

                //gambar pintu exit di posisi pintuExit di kedua page
                setviewport((level.pintuExit.kolom)*MATRIX_ELEMENT_SIZE, (level.pintuExit.baris)*MATRIX_ELEMENT_SIZE, (level.pintuExit.kolom + 1)*MATRIX_ELEMENT_SIZE, (level.pintuExit.baris + 1)*MATRIX_ELEMENT_SIZE, 1);
                clearviewport();
                setviewport(0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
                drawUp(level.arr, level.pintuExit.kolom, level.pintuExit.baris, 2);
                swapbuffers();

                setviewport((level.pintuExit.kolom)*MATRIX_ELEMENT_SIZE, (level.pintuExit.baris)*MATRIX_ELEMENT_SIZE, (level.pintuExit.kolom + 1)*MATRIX_ELEMENT_SIZE, (level.pintuExit.baris + 1)*MATRIX_ELEMENT_SIZE, 1);
                clearviewport();
                setviewport(0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
                drawUp(level.arr, level.pintuExit.kolom, level.pintuExit.baris, 2);
                swapbuffers();

            }

            //cek apabila player sudah ada di pintu exit
            if(done(level.arr, player.pm.baris, player.pm.kolom))
            {
                waktu_Akhir(&wktselesai);
                wkttotal = hitung_Waktu(wktmulai, wktselesai);
                score = hitung_skor_akhir(&score, wkttotal);
                tampilan_exit(wkttotal,score);
                (level.lv)++;
                break;
            }
        }
        //PlaySound(NULL,NULL,0);
    }
}

int main()
{
    while(1){
        menutama();
    }
    return 0;
}
