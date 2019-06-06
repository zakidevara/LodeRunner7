#include "main.h"
#include "181511057.h"
#include "181511003.h"
#include "181511044.h"
#include "181511037.h"
#include "181511028.h"
#include "181511004.h"


void keluarPintuExit(infoLevel* level, blockSprite block){
    level->arr[level->exitPos.baris][level->exitPos.kolom] = 5;

    //gambar pintu exit di posisi exitPos di kedua page
    setviewport((level->exitPos.kolom)*MATRIX_ELEMENT_SIZE, (level->exitPos.baris)*MATRIX_ELEMENT_SIZE, (level->exitPos.kolom + 1)*MATRIX_ELEMENT_SIZE, (level->exitPos.baris + 1)*MATRIX_ELEMENT_SIZE, 1);
    clearviewport();
    setviewport(0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
    drawUp(level->arr, level->exitPos.kolom, level->exitPos.baris, 2, block);
    swapbuffers();

    setviewport((level->exitPos.kolom)*MATRIX_ELEMENT_SIZE, (level->exitPos.baris)*MATRIX_ELEMENT_SIZE, (level->exitPos.kolom + 1)*MATRIX_ELEMENT_SIZE, (level->exitPos.baris + 1)*MATRIX_ELEMENT_SIZE, 1);
    clearviewport();
    setviewport(0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
    drawUp(level->arr, level->exitPos.kolom, level->exitPos.baris, 2, block);
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
    pnode_t headLvl;                        // nilai matriks map dan posisi awal sprite dalam level

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


    /* -------------- Menampilkan Layar Loading -------------- */
    loading();


    /* -------------- Membuat Semua Level -------------- */
    headLvl = plist(MAX_LEVEL);


    /* -------------- Load Animasi Sprite -------------- */
    setactivepage(0);
    playerAnim = loadSpriteAnim('P');
    botAnim = loadSpriteAnim('B');

    while(!null(headLvl)){
        /* -------------- Inisiasi Queue Lubang -------------- */
        queueLubang = inisiasi_queue();


        /* -------------- Assign Posisi Awal Player dan Bot -------------- */
        player.pm = headLvl->info.playerPos;
        player.koor = getKoordinat(player.pm);

        for(int i = 0; i < headLvl->info.jmlBot; i++){
            bot[i].pm = headLvl->info.botPos[i];
            bot[i].koor = getKoordinat(bot[i].pm);
        }
        /* ------------------------------------------------------------ */


        //PlaySound(TEXT("audio/101-opening.wav"), NULL, SND_ASYNC);
        /* -------------- Inisiasi Page Double Buffering & Penggambaran Kondisi Awal Level -------------- */
        setactivepage(0);
        cleardevice();
        drawStage(headLvl->info.arr, player.koor, bot, headLvl->info.jmlBot, block, botAnim, playerAnim);
        tampil_skor(user.score);
        tampil_level(headLvl->info.lv);

        setactivepage(1);
        cleardevice();
        drawStage(headLvl->info.arr, player.koor, bot, headLvl->info.jmlBot, block, botAnim, playerAnim);
        tampil_skor(user.score);
        tampil_level(headLvl->info.lv);

        setactivepage(0);
        setvisualpage(1);
        /* ------------------------------------------------------------ */


        /* -------------- Mulai Permainan -------------- */
        //Simpan Waktu Awal
        waktu_Awal(&wktmulai);
        while(true){
            // Proses jika player mengambil koin
            if(lagiNgambilKoin(headLvl->info.arr, player.pm.baris, player.pm.kolom)){
                headLvl->info.arr[player.pm.baris][player.pm.kolom] = 0;
                hitung_skor(&(user.score));
            }

            // Menampilkan level yang sedang dimainkan
            tampil_level(headLvl->info.lv);

            // Menampilkan score player
            tampil_skor(user.score);

            // Baca Input User
            if(isFalling(headLvl->info.arr, player.pm.baris, player.pm.kolom) && !isSliding(headLvl->info.arr, player.pm.baris, player.pm.kolom)){
                //jika sedang jatuh maka player.movement dianggap bernilai 'S', atau sama dengan sedang bergerak ke bawah
                player.movement = FALL;
            }else{
                while(kbhit()){
                    player.movement = cekInput(toupper(getch()), &statMode);
                }
            }

            // Memproses pergerakan yang diinput user
            playerMovement(headLvl->info.arr, &queueLubang, &player);

            //Proses pergerakan bot[0]
            if(isFalling(headLvl->info.arr,bot[0].pm.baris, bot[0].pm.kolom) && !isSliding(headLvl->info.arr, bot[0].pm.baris, bot[0].pm.kolom)){
                //jika sedang jatuh maka bot[0].movement dianggap bernilai 'S', atau sama dengan sedang bergerak ke bawah
                bot[0].movement = FALL;
            }else{
                bot[0].movement = 'D';
            }
            playerMovement(headLvl->info.arr, &queueLubang, &bot[0]);

            // Print stats semua variabel yang ada jika statMode = true
            if(statMode) printStats(headLvl->info, player, wktmulai, clock(), bot, queueLubang, user);

            // Pengembalian lubang yg dibom
            if(queueLubang.Count > 0){ // apabila ada lubang di dalam map
                isi_kembali_lubang(headLvl->info.arr, &queueLubang, clock(), block);
            }

            // Update posisi sprite dalam matriks sesuai koordinatnya
            player.pm = getPosisiMatriks(player.koor);
            for(int i = 0; i < headLvl->info.jmlBot; i++){
                bot[i].pm = getPosisiMatriks(bot[i].koor);
            }

            // Penghapusan gambar player dan bot sebelumnya
            eraseDrawing(&player);
            eraseBotArray(bot, headLvl->info.jmlBot);

            // Penggambaran ulang player dan bot
            drawBotArray(headLvl->info.arr, bot, headLvl->info.jmlBot, block, botAnim);
            drawMovement(headLvl->info.arr, &player, block, playerAnim);
            delay(50);

            // Reset animasi melempar bom jika player melakukan player.movement lain
            resetAnimasiBom(headLvl->info.arr, player.pm.baris, player.pm.kolom, &player.urutanAnimasi, &player.urutanBom, player.movement, player.koor, block);

            // Ganti page buffer yang digunakan
            swapbuffers();

            // Reset nilai player.movement
            player.movement = NULL;

            // Cek apa semua koin sudah terkumpul
            if(!adakoin(headLvl->info.arr) && (headLvl->info.arr[headLvl->info.exitPos.baris][headLvl->info.exitPos.kolom] != 5)) keluarPintuExit(&(headLvl->info), block);

            // Cek apabila player sudah ada di pintu exit
            if(done(headLvl->info.arr, player.pm.baris, player.pm.kolom))
            {
                waktu_Akhir(&wktselesai);
                wkttotal = hitung_Waktu(wktmulai, wktselesai);
                user.score = hitung_skor_akhir(user.score, wkttotal);
                tampilan_exit(wkttotal,user.score);
                sub_head(&headLvl);
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
