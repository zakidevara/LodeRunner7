#include "main.h"
#include "181511057.h"
#include "181511003.h"
#include "181511028.h"
#include "181511037.h"
#include "181511044.h"

#include "181511004.h"


void tampil_pause_menu(){
    void* temp = (void*) malloc(imagesize(0, 0, WINDOWS_WIDTH - 1, WINDOWS_HEIGHT - 1));
    int curPage = getactivepage();
    getimage(0, 0, WINDOWS_WIDTH - 1, WINDOWS_HEIGHT - 1, temp);
    setactivepage(3);
    cleardevice();
    putimage(0, 0, temp, COPY_PUT);

    setviewport(200, 150, WINDOWS_WIDTH-200, WINDOWS_HEIGHT-150, 1);
    clearviewport();
    setviewport(0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);


    rectangle(200, 150, WINDOWS_WIDTH-200, WINDOWS_HEIGHT-150);
    settextstyle(COMPLEX_FONT, 0, 8);
    outtextxy(450, 250, "GAME PAUSED");
    outtextxy(350, 350, "Press Any Key to Continue");
    setvisualpage(3);
    getch();
    setactivepage(curPage);
    setvisualpage(1-curPage);
    free(temp);
}


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

    QueueLubang qLubang;                 // queue untuk bata yang dilubangi

    tUser user;                             // Data user yang sedang memainkan game

    bool statMode = false;                  // Untuk toggle statMode

    blockSprite block = loadBlockSprites(); // Untuk menyimpan data gambar sprite block di memory

    spriteAnim playerAnim;
    spriteAnim botAnim;

    int playerSpeed = 10;
    int botSpeed = 5;

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
        /* -------------- Assign Posisi Awal Player dan Bot -------------- */
        player.pm = headLvl->info.playerPos;
        player.koor = getKoordinat(player.pm);

        for(int i = 0; i < headLvl->info.jmlBot; i++){
            bot[i].pm = headLvl->info.botPos[i];
            bot[i].koor = getKoordinat(bot[i].pm);
        }

        /* -------------- Inisiasi Page Double Buffering & Penggambaran Kondisi Awal Level -------------- */
        setactivepage(0);
        cleardevice();
        drawStage(headLvl->info.arr, player.koor, bot, headLvl->info.jmlBot, block, botAnim, playerAnim);

        setactivepage(1);
        cleardevice();
        drawStage(headLvl->info.arr, player.koor, bot, headLvl->info.jmlBot, block, botAnim, playerAnim);

        setactivepage(0);
        setvisualpage(1);
        /* ------------------------------------------------------------ */


        /* -------------- Mulai Permainan -------------- */
        //Simpan Waktu Awal
        waktu_Awal(&wktmulai);

        while(true){
            soundBGM(PLAY);
            // Proses jika player mengambil koin
            if(lagiNgambilKoin(headLvl->info.arr, player.pm.baris, player.pm.kolom)){
                headLvl->info.arr[player.pm.baris][player.pm.kolom] = 0;
                soundGetCoin(PLAY);
                hitung_skor(&(user.score));
            }
            for(int i = 0; i < headLvl->info.jmlBot; i++)
            {
                if(bot[i].coin == false)
                {
                    if(lagiNgambilKoin(headLvl->info.arr, bot[i].pm.baris, bot[i].pm.kolom))
                    {
                        headLvl->info.arr[bot[i].pm.baris][bot[i].pm.kolom] = 0;
                        bot[i].coin = true;
                    }
                }

            }

            /* ----- Menampilkan Scorebar ----- */
            eraseScorebar();
            tampil_level(headLvl->info.lv);
            tampil_skor(user.score);
            tampil_durasi_permainan(hitung_Waktu(wktmulai, clock()));
            tampil_lives(player.lives);


            // Baca Input User
            if(isTrapped(headLvl->info.arr, player.koor.X, player.koor.Y, 'P')){
                player.movement = NULL;
                player.koor.X =  player.pm.kolom*MATRIX_ELEMENT_SIZE;
                player.koor.Y =  player.pm.baris*MATRIX_ELEMENT_SIZE;
                headLvl->info.arr[player.pm.baris][player.pm.kolom] = 9;
            }else if(isFalling(headLvl->info.arr, player.koor.X, player.koor.Y) && !isSliding(headLvl->info.arr, player.koor.X, player.koor.Y)){
                //jika sedang jatuh maka player.movement dianggap bernilai 'S', atau sama dengan sedang bergerak ke bawah
                player.movement = FALL;
            }else{
                while(kbhit()){
                    player.movement = cekInput(toupper(getch()), &statMode);
                }
            }

            // Memproses pergerakan yang diinput user
            playerMovement(headLvl->info.arr, &qLubang, &player, playerSpeed);
            //if(player.movement == FALL) soundFalling(PLAY);

            //Proses pergerakan bot
            for(int i = 0; i < headLvl->info.jmlBot; i++){
                //generate movement bot

                if(isTrapped(headLvl->info.arr, bot[i].koor.X, bot[i].koor.Y, 'B')){
                    bot[i].movement = NULL;
                    bot[i].koor.X =  bot[i].pm.kolom*MATRIX_ELEMENT_SIZE;
                    bot[i].koor.Y =  bot[i].pm.baris*MATRIX_ELEMENT_SIZE;
                    headLvl->info.arr[bot[i].pm.baris][bot[i].pm.kolom] = 9;

                    if(bot[i].coin == true)
                    {
                        koinBot(&(bot[i].coin), headLvl->info.arr, bot[i].pm.baris, bot[i].pm.kolom);
                    }
                }else if(headLvl->info.arr[bot[i].pm.baris][bot[i].pm.kolom] == 1){
                    bot[i].lives= bot[i].lives - 1;
                    bot[i].pm.baris -= 1;
                    bot[i].koor = getKoordinat(bot[i].pm);
                    if(bot[i].lives <= 0)
                    {
                        resetBot(&bot[i].pm, headLvl->info.botPos[i], &bot[i].lives);
                        bot[i].koor = getKoordinat(bot[i].pm);
                    }

                }else if(isFalling(headLvl->info.arr, bot[i].koor.X, bot[i].koor.Y) && !isSliding(headLvl->info.arr, bot[i].koor.X, bot[i].koor.Y)){
                    //jika sedang jatuh maka bot[i].movement dianggap bernilai 'S', atau sama dengan sedang bergerak ke bawah
                    bot[i].movement = FALL;
                }else if(!isSamePos(bot[i].pm, player.pm)){
                    bot[i].movement = A_Star(headLvl->info.arr, bot[i].pm, player.pm, i, bot, headLvl->info.jmlBot);
                }
            }
            for(int i = 0; i < headLvl->info.jmlBot; i++){
                playerMovement(headLvl->info.arr, &qLubang, &bot[i], botSpeed);
                //if(bot[i].movement == FALL) soundFalling(PLAY);
            }


            // Print stats semua variabel yang ada jika statMode = true
            if(statMode) printStats(headLvl->info, player, wktmulai, clock(), bot, qLubang, user);

            // Pengembalian lubang yg dibom
            if(qLubang.Front != NULL){ // apabila ada lubang di dalam map
                isi_kembali_lubang(headLvl->info.arr, &qLubang, clock(), block);
            }

            // Update posisi sprite dalam matriks sesuai koordinatnya
            player.pm = getPosisiMatriks(player.koor);
            for(int i = 0; i < headLvl->info.jmlBot; i++){
                bot[i].pm = getPosisiMatriksBot(bot[i].koor);
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
            else if(ismeetbot(headLvl->info.arr, player, &(player.lives), bot, headLvl->info.jmlBot) || isinbrick(headLvl->info.arr, player.pm, &(player.lives))){
                break;
            }

        }
    }
    /* ------------------- Permainan Selesai ------------------- */
    soundBGM(STOP);

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
