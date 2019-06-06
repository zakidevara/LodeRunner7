#include "main.h"
#include "181511057.h"
#include "181511003.h"
#include "181511044.h"
#include "181511037.h"
#include "181511028.h"
#include "181511004.h"


void keluarPintuExit(infoLevel* level, blockSprite block){
    level->arr[level->pintuExit.baris][level->pintuExit.kolom] = 5;

    //gambar pintu exit di posisi pintuExit di kedua page
    setviewport((level->pintuExit.kolom)*MATRIX_ELEMENT_SIZE, (level->pintuExit.baris)*MATRIX_ELEMENT_SIZE, (level->pintuExit.kolom + 1)*MATRIX_ELEMENT_SIZE, (level->pintuExit.baris + 1)*MATRIX_ELEMENT_SIZE, 1);
    clearviewport();
    setviewport(0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
    drawUp(level->arr, level->pintuExit.kolom, level->pintuExit.baris, 2, block);
    swapbuffers();

    setviewport((level->pintuExit.kolom)*MATRIX_ELEMENT_SIZE, (level->pintuExit.baris)*MATRIX_ELEMENT_SIZE, (level->pintuExit.kolom + 1)*MATRIX_ELEMENT_SIZE, (level->pintuExit.baris + 1)*MATRIX_ELEMENT_SIZE, 1);
    clearviewport();
    setviewport(0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
    drawUp(level->arr, level->pintuExit.kolom, level->pintuExit.baris, 2, block);
    swapbuffers();
}

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
    /* ---------------------------- VARIABEL LOKAL ---------------------------- */
    infoLevel level;                        // nilai matriks map dan posisi awal sprite dalam level

    spriteInfo player;                          // sprite player
    spriteInfo bot[5];                          // sprite bot

    clock_t wktmulai,wktselesai;            // mencatat waktu mulai dan waktu selesai dalam satu stage
    double wkttotal;                        // mencatat durasi penyelesaian stage

    arrayQueue queueLubang;                 // queue untuk bata yang dilubangi

    tUser user;                             // Data user yang sedang memainkan game

    bool statMode = false;                  // Untuk toggle statMode

    blockSprite block = loadBlockSprites(); // Untuk menyimpan data gambar sprite block di memory

    spriteAnim playerAnim;
    spriteAnim botAnim;

    /* ------------------------------------------------------------------------ */


    level.lv = 1;
    while(level.lv <= MAX_LEVEL){
        /* -------------- Inisiasi Queue Lubang -------------- */
        queueLubang = inisiasi_queue();


        /* -------------- Membuat Semua Level -------------- */
        level = generateLevel(level.lv);


        /* -------------- Assign Posisi Awal Player dan Bot -------------- */
        player.pm = level.player;
        player.koor = getKoordinat(player.pm);

        for(int i = 0; i < level.jmlBot; i++){
            bot[i].pm = level.bot[i];
            bot[i].koor = getKoordinat(bot[i].pm);
        }
        /* ------------------------------------------------------------ */


        //PlaySound(TEXT("audio/101-opening.wav"), NULL, SND_ASYNC);
        /* -------------- Menampilkan Layar Loading -------------- */
        loading();


        /* -------------- Load Animasi Sprite -------------- */
        playerAnim = loadSpriteAnim('P');
        botAnim = loadSpriteAnim('B');


        /* -------------- Inisiasi Page Double Buffering & Penggambaran Kondisi Awal Level -------------- */
        setactivepage(0);
        cleardevice();
        drawStage(level.arr, player.koor, bot, level.jmlBot, block, botAnim, playerAnim);
        tampil_skor(user.score);
        tampil_level(level.lv);

        setactivepage(1);
        cleardevice();
        drawStage(level.arr, player.koor, bot, level.jmlBot, block, botAnim, playerAnim);
        tampil_skor(user.score);
        tampil_level(level.lv);

        setactivepage(0);
        setvisualpage(1);
        /* ------------------------------------------------------------ */


        /* -------------- Mulai Permainan -------------- */
        //Simpan Waktu Awal
        waktu_Awal(&wktmulai);
        while(true){
            // Proses jika player mengambil koin
            if(lagiNgambilKoin(level.arr, player.pm.baris, player.pm.kolom)){
                level.arr[player.pm.baris][player.pm.kolom] = 0;
                hitung_skor(&(user.score));
            }

            // Menampilkan level yang sedang dimainkan
            tampil_level(level.lv);

            // Menampilkan score player
            tampil_skor(user.score);

            // Baca Input User
            if(isFalling(level.arr, player.pm.baris, player.pm.kolom) && !isSliding(level.arr, player.pm.baris, player.pm.kolom)){
                //jika sedang jatuh maka player.movement dianggap bernilai 'S', atau sama dengan sedang bergerak ke bawah
                player.movement = FALL;
            }else{
                while(kbhit()){
                    player.movement = cekInput(toupper(getch()), &statMode);
                }
            }

            // Memproses pergerakan yang diinput user
            playerMovement(level.arr, &queueLubang, &player);

            //Proses pergerakan bot[0]
            if(isFalling(level.arr,bot[0].pm.baris, bot[0].pm.kolom) && !isSliding(level.arr, bot[0].pm.baris, bot[0].pm.kolom)){
                //jika sedang jatuh maka bot[0].movement dianggap bernilai 'S', atau sama dengan sedang bergerak ke bawah
                bot[0].movement = FALL;
            }else{
                bot[0].movement = 'D';
            }
            playerMovement(level.arr, &queueLubang, &bot[0]);

            // Print stats semua variabel yang ada jika statMode = true
            if(statMode) printStats(level, player, wktmulai, clock(), bot, queueLubang, user);

            // Pengembalian lubang yg dibom
            if(queueLubang.Count > 0){ // apabila ada lubang di dalam map
                isi_kembali_lubang(level.arr, &queueLubang, clock(), block);
            }

            // Update posisi sprite dalam matriks sesuai koordinatnya
            player.pm = getPosisiMatriks(player.koor);
            for(int i = 0; i < level.jmlBot; i++){
                bot[i].pm = getPosisiMatriks(bot[i].koor);
            }

            // Penghapusan gambar player dan bot sebelumnya
            eraseDrawing(&player);
            eraseBotArray(bot, level.jmlBot);

            // Penggambaran ulang player dan bot
            drawBotArray(level.arr, bot, level.jmlBot, block, botAnim);
            drawMovement(level.arr, &player, block, playerAnim);
            delay(50);

            // Reset animasi melempar bom jika player melakukan player.movement lain
            resetAnimasiBom(level.arr, player.pm.baris, player.pm.kolom, &player.urutanAnimasi, &player.urutanBom, player.movement, player.koor, block);

            // Ganti page buffer yang digunakan
            swapbuffers();

            // Reset nilai player.movement
            player.movement = NULL;

            // Cek apa semua koin sudah terkumpul
            if(!adakoin(level.arr) && (level.arr[level.pintuExit.baris][level.pintuExit.kolom] != 5)) keluarPintuExit(&level, block);

            // Cek apabila player sudah ada di pintu exit
            if(done(level.arr, player.pm.baris, player.pm.kolom))
            {
                waktu_Akhir(&wktselesai);
                wkttotal = hitung_Waktu(wktmulai, wktselesai);
                user.score = hitung_skor_akhir(user.score, wkttotal);
                tampilan_exit(wkttotal,user.score);
                (level.lv)++;
                break;
            }
        }

        //PlaySound(NULL,NULL,0);
    }
    /* ------------------- Permainan Selesai ------------------- */


    /* ------------------- Input Nama dan Catat di Highscore ------------------- */
    inputNama(user.nama ,50);
    writeFileHighScore(user);
    /* ------------------------------------------------------------------------- */
}

int main()
{
    while(true){
        menutama();
    }
    closegraph();
    return 0;
}
