/* File         : 181511057.cpp               */
/* Nama Pembuat : Muhammad Zaki Devara      */
/* NIM          : 181511057                 */

#include "181511057.h"

/*---------------------------- Load/Animasi Sprite ----------------------------*/
void drawAnimRunningRight(int x, int y, int* urutan, spriteAnim anim){
    if((*urutan > 7) ||(*urutan < 0)) *urutan = 0;
    switch(*urutan){
    case 0:
        putimage(x, y, anim.running[0], OR_PUT);break;
    case 1:
        putimage(x, y, anim.running[1], OR_PUT);break;
    case 2:
        putimage(x, y, anim.running[2], OR_PUT);break;
    case 3:
        putimage(x, y, anim.running[3], OR_PUT);break;
    case 4:
        putimage(x, y, anim.running[4], OR_PUT);break;
    case 5:
        putimage(x, y, anim.running[5], OR_PUT);break;
    case 6:
        putimage(x, y, anim.running[6], OR_PUT);break;
    case 7:
        putimage(x, y, anim.running[7], OR_PUT);break;
    }
    (*urutan)++;
    if(*urutan > 7) *urutan = 0;
}

void drawAnimRunningLeft(int x, int y, int* urutan, spriteAnim anim){
    if((*urutan > 15) ||(*urutan < 8)) *urutan = 8;
    switch(*urutan){
    case 8:
        putimage(x, y, anim.running[8], OR_PUT);break;
    case 9:
        putimage(x, y, anim.running[9], OR_PUT);break;
    case 10:
        putimage(x, y, anim.running[10], OR_PUT);break;
    case 11:
        putimage(x, y, anim.running[11], OR_PUT);break;
    case 12:
        putimage(x, y, anim.running[12], OR_PUT);break;
    case 13:
        putimage(x, y, anim.running[13], OR_PUT);break;
    case 14:
        putimage(x, y, anim.running[14], OR_PUT);break;
    case 15:
        putimage(x, y, anim.running[15], OR_PUT);break;
    }

    (*urutan)++;
    if(*urutan > 15) *urutan = 8;
}

void drawAnimClimbRopeRight(int x,int y, int* urutan, spriteAnim anim){
    if((*urutan > 1) || (*urutan < 0)) *urutan = 0;
    switch(*urutan){
    case 0:
        putimage(x, y, anim.climbingRope[0], OR_PUT);break;
    case 1:
        putimage(x, y, anim.climbingRope[1], OR_PUT);break;
    default:
        putimage(x, y, anim.climbingRope[0], OR_PUT);break;
    }
    (*urutan)++;
    if((*urutan > 1)) *urutan = 0;
}

void drawAnimClimbRopeLeft(int x,int y, int* urutan, spriteAnim anim){
    if((*urutan > 3) || (*urutan < 2)) *urutan = 2;
    switch(*urutan){
    case 2:
        putimage(x, y, anim.climbingRope[2], OR_PUT);break;
    case 3:
        putimage(x, y, anim.climbingRope[3], OR_PUT);break;
    default:
        putimage(x, y, anim.climbingRope[2], OR_PUT);break;
    }
    (*urutan)++;
    if((*urutan > 3)) *urutan = 2;
}

void drawAnimClimbLadder(int x,int y, int* urutan, spriteAnim anim){
    if(*urutan > 1) *urutan = 0;
    switch(*urutan){
    case 0:
        putimage(x, y, anim.climbingLadder[0], OR_PUT);break;
    case 1:
        putimage(x, y, anim.climbingLadder[1], OR_PUT);break;
    default:
        putimage(x, y, anim.climbingLadder[0], OR_PUT);break;
    }
    (*urutan)++;
    if(*urutan > 1) *urutan = 0;
}

void drawAnimBombRight(int x,int y, spriteAnim anim){
    putimage(x, y, anim.bombing[0], OR_PUT);
}

void drawAnimBombLeft(int x,int y, spriteAnim anim){
    putimage(x, y, anim.bombing[1], OR_PUT);
}


/*---------------------------- Animasi Bata ----------------------------*/
void bataDestroyed(int x1,int y1,int x2, int y2, int urutan){
    switch(urutan){
    case 0:
        readimagefile("images/bata_destroyed/bata_destroyed0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/bata_destroyed/bata_destroyed1.gif", x1, y1, x2-1, y2-1);break;
    case 2:
        readimagefile("images/bata_destroyed/bata_destroyed2.gif", x1, y1, x2-1, y2-1);break;
    case 3:
        readimagefile("images/bata_destroyed/bata_destroyed3.gif", x1, y1, x2-1, y2-1);break;
    }
}

void returnBata(int x1,int y1,int x2, int y2, int* urutan){
    switch(*urutan){
    case 0:
        readimagefile("images/return_bata/return_bata0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/return_bata/return_bata1.gif", x1, y1, x2-1, y2-1);break;
    case 2:
        readimagefile("images/return_bata/return_bata2.gif", x1, y1, x2-1, y2-1);break;
    default:
        readimagefile("images/bata.gif", x1, y1, x2-1, y2-1);
    }
    (*urutan)++;
}


/*---------------------------- Operasi Penggambaran ----------------------------*/
void drawMovement(int arr[BARIS][KOLOM], spriteInfo* player, blockSprite block, spriteAnim anim){
    switch((*player).movement){
    case KEY_LEFT :
    case 'A' :
            //gambar ulang map
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris,4, block);
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris-1,3, block);
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris+1,3, block);

            //gambar ulang karakter utama
            if(isSliding(arr, player->koor.X, player->koor.Y)){
                drawAnimClimbRopeLeft(player->koor.X, player->koor.Y, &(player->urutanAnimasi), anim);
            }else{
                drawAnimRunningLeft(player->koor.X, player->koor.Y, &(player->urutanAnimasi), anim);
            }
            break;
    case KEY_RIGHT :
    case 'D' :
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris,4, block);
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris-1,3, block);
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3, block);
            if(isSliding(arr,  player->koor.X, player->koor.Y)){
                drawAnimClimbRopeRight(player->koor.X, player->koor.Y, &(player->urutanAnimasi), anim);
            }else{
                drawAnimRunningRight(player->koor.X, player->koor.Y, &(player->urutanAnimasi), anim);
            }
            break;
    case KEY_UP :
    case 'W' :
            drawDown(arr, (*player).pm.kolom, (*player).pm.baris-1,4, block);
            drawDown(arr, (*player).pm.kolom+1, (*player).pm.baris-1,3, block);
            drawDown(arr, (*player).pm.kolom-1, (*player).pm.baris-1,3, block);
            drawAnimClimbLadder(player->koor.X, player->koor.Y, &(player->urutanAnimasi), anim);
            break;
    case FALL :
    case KEY_DOWN :
    case 'S' :
            drawUp(arr, (*player).pm.kolom, (*player).pm.baris+1,4, block);
            drawUp(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3, block);
            drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3, block);
            if(isClimbing(arr,  player->koor.X, player->koor.Y)){
                drawAnimClimbLadder(player->koor.X, player->koor.Y, &(player->urutanAnimasi), anim);
            }else{
                drawAnimRunningRight(player->koor.X, player->koor.Y, &(player->urutanAnimasi), anim);
            }
            break;
    case 'X' :
    //case 'M' :
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris-1,3, block);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris,3, block);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3, block);
            drawAnimBombRight(player->koor.X, player->koor.Y, anim);

            bataDestroyed(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE, (*player).urutanBom);
            delay(15);
            if((*player).urutanBom == 3){
                drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1, 2, block);
                drawAnimBombRight(player->koor.X, player->koor.Y, anim);
            }
            break;
    case 'Z' :
    case 'N' :
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris-1,3, block);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris,3, block);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3, block);
            drawAnimBombLeft(player->koor.X, player->koor.Y, anim);

            bataDestroyed(( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE, (*player).urutanBom);
            delay(15);

            if((*player).urutanBom == 3){
                drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1, 2, block);
                drawAnimBombLeft(player->koor.X, player->koor.Y, anim);
            }
            break;
    default :
            drawUp(arr, (*player).pm.kolom, (*player).pm.baris+1,3, block);
            drawUp(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3, block);
            drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3, block);
            int urutan = 0;
            if(isClimbing(arr, player->koor.X, player->koor.Y)){
                urutan = player->urutanAnimasi;
                drawAnimClimbLadder(player->koor.X, player->koor.Y, &urutan , anim);
            }else if(isSliding(arr, player->koor.X, player->koor.Y)){
                urutan = player->urutanAnimasi;
                if(player->urutanAnimasi > 1){
                    drawAnimClimbRopeLeft(player->koor.X, player->koor.Y, &urutan , anim);
                }else{
                    drawAnimClimbRopeRight(player->koor.X, player->koor.Y, &urutan , anim);
                }
            }else{
                if(player->urutanAnimasi > 7){
                    drawAnimRunningLeft(player->koor.X, player->koor.Y, &urutan , anim);
                }else{
                    drawAnimRunningRight(player->koor.X, player->koor.Y, &urutan , anim);
                }
            }

    }
}

void drawBotArray(int arr[BARIS][KOLOM], spriteInfo bot[], int nBot, blockSprite block, spriteAnim anim){
    for(int i = 0; i < nBot; i++) drawMovement(arr, &bot[i], block, anim);
}

void drawStage(int arr[BARIS][KOLOM], koordinat player, spriteInfo bot[], int nBot, blockSprite block, spriteAnim animBot, spriteAnim animPlayer){
    int urutan = 0;
    for(int i=0; i<BARIS; i++){
        for(int j=0; j<KOLOM; j++){
            //penggambaran map
            if(arr[i][j] == 1){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.brick, COPY_PUT);
            }else if(arr[i][j] == 2){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.ladder, COPY_PUT);
            }else if(arr[i][j] == 3){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.rope, COPY_PUT);
            }else if(arr[i][j] == 4){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.coin, COPY_PUT);
            }else if(arr[i][j] == 5){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.exit, COPY_PUT);
            }else if(arr[i][j] == 6){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.bedrock, COPY_PUT);
            }
        }
    }

    //penggambaran bot
    drawBotArray(arr, bot, nBot, block, animBot);

    //penggambaran player
    drawAnimRunningRight(player.X, player.Y, &urutan, animPlayer);
}

void loading(){ // menampilkan tampilan loading selagi matriks digambar
    setactivepage(3);
    settextstyle(10, 0, 8);
    outtextxy((WINDOWS_WIDTH/2)-250,(WINDOWS_HEIGHT/2)-450, "Lode Runner");
    settextstyle(10, 0, 2);
    outtextxy((WINDOWS_WIDTH/2)-75,((WINDOWS_HEIGHT-50)/2), "By Kelompok 7");
    outtextxy((WINDOWS_WIDTH/2)-150,((WINDOWS_HEIGHT-50)/2)+30, "Proyek Perangkat Lunak 2");
    setvisualpage(3);
}

void tampil_level(int level){
    char levelStr[6];

    setviewport(20,WINDOWS_HEIGHT-50, 150, WINDOWS_HEIGHT,1);
    clearviewport();
    setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

    sprintf(levelStr,"%d", level);
    outtextxy(100,WINDOWS_HEIGHT-40,levelStr);
    outtextxy(20,WINDOWS_HEIGHT-40,"LEVEL:");
}

void resetAnimasiBom(int arr[BARIS][KOLOM], int barisPlayer, int kolomPlayer, int* urutan, int* urutanBom, int movement, koordinat player, blockSprite block){
    if(!isLagiBom(movement)){
        *urutanBom = -1;
        if(arr[barisPlayer+1][kolomPlayer+1] == 7){
            arr[barisPlayer+1][kolomPlayer+1] = 1;
                setviewport((kolomPlayer+1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer+2)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr,kolomPlayer+1,barisPlayer+1,1, block);
                swapbuffers();
                setviewport((kolomPlayer+1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer+2)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr,kolomPlayer+1,barisPlayer+1,1, block);
                swapbuffers();
        }
        if(arr[barisPlayer+1][kolomPlayer-1] == 7){
            arr[barisPlayer+1][kolomPlayer-1] = 1;
            setviewport((kolomPlayer-1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            drawUp(arr,kolomPlayer-1,barisPlayer+1,1, block);
            swapbuffers();
            setviewport((kolomPlayer-1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            drawUp(arr,kolomPlayer-1,barisPlayer+1,1, block);
            swapbuffers();
        }
    }
}


/*---------------------------- Operasi Pengecekan ----------------------------*/
bool isNabrak(int arr[BARIS][KOLOM], int X, int Y, int arah){
// Pengecekan sisi kiri dan kanan player, jika ada tembok return true dan jika tidak ada return false
// arah = -1 kalau ke kiri dan arah = 1 kalau ke kanan
    int baris, kolom;

    baris = (Y +(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
    if(arah == 1){
        kolom = X/MATRIX_ELEMENT_SIZE;
    }else{
        kolom = (X+(MATRIX_ELEMENT_SIZE-1))/MATRIX_ELEMENT_SIZE;
    }

    return (arr[baris][kolom+arah] == 1) || (arr[baris][kolom+arah] == 6);
}

char cekInput(char movement, bool* statMode){ //apabila nilai movement tidak sesuai dengan kontrol yang ditetapkan, maka assign movement = NULL
    switch(movement){
    case 'W' :
    case 'S' :
    case 'A' :
    case 'D' :
    //case 'M' :
    //case 'N' :
    case KEY_UP :
    case KEY_DOWN :
    case KEY_LEFT :
    case KEY_RIGHT :
    case 'X' :
    case 'Z' : return movement;
    case '`' :  if(!(*statMode)){
                    *statMode = true;
                }else{
                    *statMode = false;
                }
                return NULL;
    case 27 :  getch(); return NULL; //pause
    default : return NULL;

    }
}

bool isLagiBom(int movement){ //cek apabila player sedang melempar bom atau tidak
    return ((movement=='M')||(movement=='N')||(movement=='Z')||(movement=='X'));
}


/*---------------------------- Operasi untuk Queue Lubang ----------------------------*/


void isi_kembali_lubang(int arr[BARIS][KOLOM], QueueLubang* P, clock_t wkt_sekarang, blockSprite block){
    lubang Z;
    double durasi = hitung_Waktu(P->Front->info.start, wkt_sekarang); //menghitung durasi = waktu sekarang - waktu lubang dibuat
    while( (durasi > 7) && (P->Front != NULL)){   // selagi durasi antrian paling depan sudah mencapai 7 detik
        //returnBata(Z.pos.kolom*MATRIX_ELEMENT_SIZE, Z.pos.baris*MATRIX_ELEMENT_SIZE, (Z.pos.kolom+1)*MATRIX_ELEMENT_SIZE, (Z.pos.baris+1)*MATRIX_ELEMENT_SIZE, &(Z.urutan));

        Z = P->dequeue();                        //keluarkan data lubang dari antrian dan tampung di variabel Z
        arr[Z.pos.baris][Z.pos.kolom] = 1;      //kembalikan lubang yang dikeluarkan dari antrian ke posisi semula

        //gambar bata yang sudah dikembalikan di posisi lubangnya di kedua page
        drawUp(arr,Z.pos.kolom,Z.pos.baris,1, block); swapbuffers();
        drawUp(arr,Z.pos.kolom,Z.pos.baris,1, block); swapbuffers();

        //hitung durasi lubang di antrian berikutnya
        if(P->Front != NULL) durasi = hitung_Waktu(P->Front->info.start, wkt_sekarang);
    }
}

lubang assign_Lubang(int baris, int kolom, clock_t waktuAwal){
    lubang Z;
    (Z).pos.baris = baris;
    (Z).pos.kolom = kolom;
    (Z).start = waktuAwal;
    return Z;
}


/*---------------------------- Operasi untuk Membaca dan Assign Design Level ----------------------------*/
infoLevel readFileLevel(char file[]){
    infoLevel level;
    FILE* pf;
    if((pf = fopen(file,"rb")) != NULL){
        for(int i = 0; i < BARIS; i++){
            for(int j = 0; j < KOLOM; j++){
                fscanf(pf,"%d ", &(level.arr[i][j]));
            }
        }
        fscanf(pf, "\n%d %d\n", &(level.exitPos.baris), &(level.exitPos.kolom));
        fscanf(pf, "%d %d\n", &(level.playerPos.baris), &(level.playerPos.kolom));
        fscanf(pf, "%d\n", &(level.jmlBot));
        for(int i = 0; i < level.jmlBot; i++){
            fscanf(pf, "%d %d\n", &(level.botPos[i].baris), &(level.botPos[i].kolom));
        }
    }
    fclose(pf);
    return level;
}

infoLevel generateLevel(int level){
    infoLevel temp;

    switch(level){
    case 1 :
        temp = readFileLevel("level/level1.dat");break;
    case 2 :
        temp = readFileLevel("level/level2.dat");break;
    case 3 :
        temp = readFileLevel("level/level3.dat");break;
    case 4 :
        temp = readFileLevel("level/level4.dat");break;
    case 5 :
        temp = readFileLevel("level/level5.dat");break;

    }
    temp.lv = level;
    return temp;
}


/*---------------------------- Operasi Konversi Koordinat dan Posisi Matriks ----------------------------*/
posisiMatriks getPosisiMatriks(koordinat koor){
    posisiMatriks pos;
    (pos).kolom = (koor.X+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
    (pos).baris = (koor.Y)/MATRIX_ELEMENT_SIZE;
    return pos;
}

posisiMatriks getPosisiMatriksBot(koordinat koor){
    posisiMatriks pos;
    (pos).kolom = (koor.X+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
    (pos).baris = (koor.Y+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
    return pos;
}

koordinat getKoordinat(posisiMatriks pos){
    koordinat koor;
    koor.X = pos.kolom * MATRIX_ELEMENT_SIZE;
    koor.Y = pos.baris * MATRIX_ELEMENT_SIZE;
    return koor;
}


/*---------------------------- Operasi untuk Fitur Highscore ----------------------------*/
void readFileHighScore(){
    FILE* hs;
    tUser temp;
    koordinat koor;
    int rank = 1;
    koor.X = 40;
    koor.Y = 90;
    char tempStr[100];

    setactivepage(0);
    cleardevice();
    settextstyle(COMPLEX_FONT, 0, 3);
    outtextxy(40, 20, "=================== HIGH SCORE ===================");
    outtextxy(40, 60, "No.");
    outtextxy(100, 60, "Nama");
    outtextxy(500, 60, "Score");
    if((hs = fopen("highscore.dat", "rb")) != NULL){
        while((fread(&temp, sizeof(tUser), 1, hs) == 1) && (rank <= 10)){
            sprintf(tempStr, "%2d.", rank);
            outtextxy(40, koor.Y, tempStr);
            sprintf(tempStr, "%s", temp.nama);
            outtextxy(100, koor.Y, tempStr);
            sprintf(tempStr, "%5d", temp.score);
            outtextxy(500, koor.Y, tempStr);
            koor.Y += 30;
            rank++;
        }
    }else{
        outtextxy(WINDOWS_WIDTH/2-100, WINDOWS_HEIGHT/2-50, "File tidak ada isinya");
    }
    fclose(hs);
    setvisualpage(0);
    getch();
}

void writeFileHighScore(tUser user){

    FILE* hs;
    if((hs = fopen("highscore.dat", "ab")) != NULL){
        fwrite(&user, sizeof(tUser), 1, hs);
    }
    fclose(hs);
}

void inputNama(char inputbuf[],int nchars) {
    int input_pos = 0;
    int the_end = 0;
    inputbuf[0] = '\0';
    char c;
    cleardevice();
    settextstyle(SANS_SERIF_FONT, 1, 4);
    do
    {
        outtextxy(40,40, "NAMA    : ");
        outtextxy (210,40, inputbuf);
        c = getch();
        switch(c){
            case 8: /* backspace */
              if (input_pos){
                    input_pos--;
                    inputbuf[input_pos] = '\0';
                    setviewport(210, 40, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
                    clearviewport();
                    setviewport(0,0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
              }
              break;
            case 13: /* return */
              the_end = 1; break;
            case 27: /* Escape = Abort */
              inputbuf[0] = '\0';
              the_end = 1; break;
            default:
              if (input_pos < 30-1 && c >= ' ' && c <= '~'){
                 inputbuf[input_pos] = c;
                 input_pos++;
                 inputbuf[input_pos] = '\0';
              }
       }
    } while (!the_end);
}


void warnateks(int warna) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, warna);
}

void printStats(infoLevel level, spriteInfo player, clock_t Start, clock_t End, spriteInfo bot[], QueueLubang qLubang, tUser user){
    system("cls");
    printf("--- LEVEL ---\n");
    printf("Level : %d\n", level.lv);
    printf("Map : \n");
    for(int i = 0; i < BARIS;i++){
        for(int j = 0; j < KOLOM; j++){
            switch(level.arr[i][j]){
            case 1 : warnateks(LIGHTRED);break;
            case 2 : warnateks(YELLOW);break;
            case 3 : warnateks(GREEN);break;
            case 4 : warnateks(MAGENTA);break;
            case 5 : warnateks(LIGHTBLUE);break;
            case 6 : warnateks(RED);break;
            case 7 : warnateks(CYAN);break;
            default : warnateks(WHITE);
            }
            printf("%d ", level.arr[i][j]);
        }
        printf("\n");
        warnateks(WHITE);
    }
    printf("Pintu Exit : %d %d\n", level.exitPos);
    printf("Posisi Player : %d %d\n", level.playerPos);
    for(int i = 0; i < level.jmlBot; i++){
        printf("Posisi Bot %d : %d %d\n", i+1, level.botPos[i]);
    }
    printf("Durasi : %lf\n", (End - Start)/(double) CLOCKS_PER_SEC);

    printf("\n--- PLAYER ---\n");
    printf("Matriks : %d %d -- Koordinat : %d %d\n", player.pm, player.koor);
    printf("Movement : %c\n", player.movement);
    printf("Animasi : %d -- Animasi Bom : %d\n", player.urutanAnimasi, player.urutanBom);

    for(int i = 0; i < level.jmlBot; i++){
        printf("\n--- BOT %d ---\n", i+1);
        printf("Matriks : %d %d -- Koordinat : %d %d\n", bot[i].pm, bot[i].koor);
        printf("Movement : %c\n", bot[i].movement);
        printf("Animasi : %d -- Animasi Bom : %d\n", bot[i].urutanAnimasi, bot[i].urutanBom);
    }

    printf("\n--- QUEUE LUBANG ---\n");
    if(qLubang.Front != NULL){
        tElmtQueueLubang* temp = qLubang.Front;
        int i = 1;
        while(temp != NULL){
            printf("Lubang %d : -Posisi : (%d, %d) -Durasi : %lf\n", i, temp->info.pos, hitung_Waktu(temp->info.start, End));
            temp = temp->next; i++;
        }
    }else{
        printf("Tidak ada lubang\n");
    }

    printf("\n--- DATA USER ---\n");
    printf("Nama : %s Score : %d\n", user.nama, user.score);

    printf("\n--- PAGE BUFFER ---\n");
    printf("Active Page : %d  Visual Page : %d", getactivepage(), getvisualpage());

    printf("\n\n");
//    for(int i = 0; i < BARIS; i++){
//        for(int j = 0; j < KOLOM; j++){
//            if(level.arr[i][j].blocked) {
//                warnateks(RED);
//            }else{
//                warnateks(GREEN);
//            }
//            printf("%d ", level.arr[i][j].blocked);
//        }
//        printf("\n");
//    }

}

void* loadSprite(const char* dir, int width, int height){
    cleardevice();
    readimagefile(dir, 0, 0, width-1, height-1);
    void* bitmap = (void*) malloc(imagesize(0,0, width-1, height-1));

    getimage(0,0, width-1, height-1, bitmap);
    return bitmap;
}

blockSprite loadBlockSprites(){
    blockSprite temp;
    temp.bedrock = loadSprite("images/bedrock.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    temp.brick = loadSprite("images/bata.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    temp.ladder = loadSprite("images/ladder.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    temp.coin = loadSprite("images/coin.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    temp.exit = loadSprite("images/exit.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    temp.rope = loadSprite("images/rope.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    return temp;
}

void eraseDrawing(spriteInfo* player){
    switch((*player).movement){
    case KEY_LEFT :
    case 'A' :
            //penghapusan gambar
            setviewport((((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom+3)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris-1)*MATRIX_ELEMENT_SIZE,((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            break;
    case KEY_RIGHT :
    case 'D' :
            setviewport((((*player).pm.kolom-2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            break;
    case KEY_UP :
    case 'W' :
            setviewport(( (*player).pm.kolom*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+3)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            break;
    case FALL :
    case KEY_DOWN :
    case 'S' :
            setviewport(( (*player).pm.kolom*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-2)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            break;
    case 'X' :
    //case 'M' :
    		setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            setviewport(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            if((*player).urutanBom == 3){
                setviewport(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            }
            break;
    case 'Z' :
    case 'N' :
    		setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            setviewport(( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, (*player).pm.kolom*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            if((*player).urutanBom == 3){
                setviewport(( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, (*player).pm.kolom*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            }
            break;
    default :
            setviewport(( ((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
    }
}

void eraseBotArray(spriteInfo bot[], int n){
    for(int i = 0; i < n; i++) eraseDrawing(&bot[i]);
}

void sortFileHighScore(){
    FILE* hs;
    tUser temp1, temp2;
    int nSwap=1;
    if((hs = fopen("highscore.dat", "rb+")) != NULL){
        while(nSwap != 0){
            nSwap = 0;
            rewind(hs);
            while((fread(&temp1, sizeof(tUser), 1, hs) == 1) && (fread(&temp2, sizeof(tUser), 1, hs))){
                if(temp1.score < temp2.score){
                    fseek(hs, (-2)*sizeof(tUser), SEEK_CUR);
                    fwrite(&temp2, sizeof(tUser), 1, hs);
                    fwrite(&temp1, sizeof(tUser), 1, hs);
                    nSwap++;
                }
                fseek(hs, (-1)*sizeof(tUser), SEEK_CUR);
            }
        }
    }
}


spriteAnim loadSpriteAnim(char c){ // c == 'P' untuk load animasi player, 'B' untuk load animasi bot
    spriteAnim temp;
    char str[255];
    if(c == 'P'){
        // load running animation
        for(int i = 0; i < 16; i++){
            switch(i){
                case 0 : strcpy(str, "images/player/Player_Right0.gif");break;
                case 1 : strcpy(str, "images/player/Player_Right1.gif");break;
                case 2 : strcpy(str, "images/player/Player_Right2.gif");break;
                case 3 : strcpy(str, "images/player/Player_Right3.gif");break;
                case 4 : strcpy(str, "images/player/Player_Right4.gif");break;
                case 5 : strcpy(str, "images/player/Player_Right5.gif");break;
                case 6 : strcpy(str, "images/player/Player_Right6.gif");break;
                case 7 : strcpy(str, "images/player/Player_Right7.gif");break;
                case 8 : strcpy(str, "images/player/Player_Left0.gif");break;
                case 9 : strcpy(str, "images/player/Player_Left1.gif");break;
                case 10 : strcpy(str, "images/player/Player_Left2.gif");break;
                case 11 : strcpy(str, "images/player/Player_Left3.gif");break;
                case 12 : strcpy(str, "images/player/Player_Left4.gif");break;
                case 13 : strcpy(str, "images/player/Player_Left5.gif");break;
                case 14 : strcpy(str, "images/player/Player_Left6.gif");break;
                case 15 : strcpy(str, "images/player/Player_Left7.gif");break;
            }
            temp.running[i] = loadSprite(str, MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        }

        // load climbLadder animation
        temp.climbingLadder[0] = loadSprite("images/player/Player_ClimbLadder0.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        temp.climbingLadder[1] = loadSprite("images/player/Player_ClimbLadder1.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);

        // load climb Rope animation
        temp.climbingRope[0] = loadSprite("images/player/Player_ClimbRope_Right0.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        temp.climbingRope[1] = loadSprite("images/player/Player_ClimbRope_Right1.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        temp.climbingRope[2] = loadSprite("images/player/Player_ClimbRope_Left0.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        temp.climbingRope[3] = loadSprite("images/player/Player_ClimbRope_Left1.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);

        // load bombing animation
        temp.bombing[0] = loadSprite("images/player/Player_ThrowBomb_Right0.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        temp.bombing[1] = loadSprite("images/player/Player_ThrowBomb_Left0.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);

    }else if(c == 'B'){ // Load animasi bot
        // load running animation
        for(int i = 0; i < 16; i++){
            switch(i){
                case 0 : strcpy(str, "images/bot/Bot_Right0.gif");break;
                case 1 : strcpy(str, "images/bot/Bot_Right1.gif");break;
                case 2 : strcpy(str, "images/bot/Bot_Right2.gif");break;
                case 3 : strcpy(str, "images/bot/Bot_Right3.gif");break;
                case 4 : strcpy(str, "images/bot/Bot_Right4.gif");break;
                case 5 : strcpy(str, "images/bot/Bot_Right5.gif");break;
                case 6 : strcpy(str, "images/bot/Bot_Right6.gif");break;
                case 7 : strcpy(str, "images/bot/Bot_Right7.gif");break;
                case 8 : strcpy(str, "images/bot/Bot_Left0.gif");break;
                case 9 : strcpy(str, "images/bot/Bot_Left1.gif");break;
                case 10 : strcpy(str, "images/bot/Bot_Left2.gif");break;
                case 11 : strcpy(str, "images/bot/Bot_Left3.gif");break;
                case 12 : strcpy(str, "images/bot/Bot_Left4.gif");break;
                case 13 : strcpy(str, "images/bot/Bot_Left5.gif");break;
                case 14 : strcpy(str, "images/bot/Bot_Left6.gif");break;
                case 15 : strcpy(str, "images/bot/Bot_Left7.gif");break;
            }
            temp.running[i] = loadSprite(str, MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        }

        // load climbLadder animation
        temp.climbingLadder[0] = loadSprite("images/player/Player_ClimbLadder0.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        temp.climbingLadder[1] = loadSprite("images/player/Player_ClimbLadder1.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);

        // load climb Rope animation
        temp.climbingRope[0] = loadSprite("images/player/Player_ClimbRope_Right0.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        temp.climbingRope[1] = loadSprite("images/player/Player_ClimbRope_Right1.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        temp.climbingRope[2] = loadSprite("images/player/Player_ClimbRope_Left0.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        temp.climbingRope[3] = loadSprite("images/player/Player_ClimbRope_Left1.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);

        // load bombing animation
        temp.bombing[0] = loadSprite("images/player/Player_ThrowBomb_Right0.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
        temp.bombing[1] = loadSprite("images/player/Player_ThrowBomb_Left0.gif",MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    }
    return temp;
}

void tampil_durasi_permainan(double durasi){
    char str[10];

    sprintf(str,"%0.1lf", durasi);
    outtextxy(WINDOWS_WIDTH-250,WINDOWS_HEIGHT-40,str);
    outtextxy(WINDOWS_WIDTH-350,WINDOWS_HEIGHT-40,"TIME:");
}


void tampil_lives(int lives){
    char str[10];

    sprintf(str,"%d", lives);
    outtextxy(WINDOWS_WIDTH-450,WINDOWS_HEIGHT-40,str);
    outtextxy(WINDOWS_WIDTH-550,WINDOWS_HEIGHT-40,"LIVES:");
}

void generateGrid(tElmtGrid grid[BARIS][KOLOM], int arr[BARIS][KOLOM], int botIndex, spriteInfo bot[], int jmlBot){

    for(int i = 0; i < BARIS; i++){
        for(int j = 0; j < KOLOM; j++){
            grid[i][j].info = arr[i][j];
        }
    }

    for(int j = 0; j< KOLOM; j++){
        for(int i = 0; i < BARIS; i++){
            grid[i][j].pos.kolom = j;
            grid[i][j].pos.baris = i;
            grid[i][j].f = FLT_MAX;
            grid[i][j].g = FLT_MAX;
            grid[i][j].h = FLT_MAX;
            grid[i][j].parent.baris = -1;
            grid[i][j].parent.kolom = -1;
//            if(((isStanding(arr, i, j-1) && !isNabrak(arr, j*MATRIX_ELEMENT_SIZE, i*MATRIX_ELEMENT_SIZE, -1) && (j > 0)) || (isStanding(arr, i, j+1) && !isNabrak(arr, j*MATRIX_ELEMENT_SIZE, i*MATRIX_ELEMENT_SIZE, 1) && (j < KOLOM-1))) &&(isFalling(arr, i, j)) && (grid[i][j] != 1)){
//                grid[i][j].blocked = false;
//            }else
            if((((grid[i+1][j].info == 0) || (grid[i+1][j].info == 4) || (grid[i+1][j].info == 3)) && (grid[i][j].info == 0)) || (grid[i][j].info == 1) || (grid[i][j].info == 6) || (grid[i][j].info == 9)){
                grid[i][j].blocked = true;
            }else{
                grid[i][j].blocked = false;
            }

            for(int i = 0; i < jmlBot; i++){
                if(i != botIndex) grid[bot[i].pm.baris][bot[i].pm.kolom].blocked = true;
            }
        }
    }
}

char A_Star(int arr[BARIS][KOLOM], posisiMatriks start, posisiMatriks end, int botIndex, spriteInfo bot[], int jmlBot){
    // Mulai A Star Pathfinding (4 Arah)
    tElmtGrid grid[BARIS][KOLOM];
    ListGrid openSet;           // Menampung grid yang masih harus diperiksa
    ListGrid closedSet;         // Menampung grid yang sudah beres diperiksa
    tElmtGrid cur;
    tElmtGrid curNeighbor;
    bool foundEnd = false;

    // Semua f, g, h di assign ke infinity (FLT_MAX)
    // Semua parent diassign ke (-1, -1) -> Tidak punya parent semua
    // Menentukan apakah path terhalangi (blocked) atau tidak
    generateGrid(grid, arr, botIndex, bot, jmlBot);

    //inisiasi nilai awal grid start
    grid[start.baris][start.kolom].f = 0;
    grid[start.baris][start.kolom].g = 0;
    grid[start.baris][start.kolom].h = 0;

    //push grid start ke openSet secara terurut dari kecil sampai besar
    openSet.push_sorted(grid[start.baris][start.kolom]);

    while((openSet.head != NULL) && !foundEnd){
        //cari yang f nya paling kecil di openSet lalu pop
        cur = openSet.pop(openSet.head->info);

        double gNew, hNew, fNew;
        int dirX[] = {0,0, -1, 1};
        int dirY[] = {-1,1,0,0};

        // Pengecekan 4 neighbor dari cur
        for(int i = 0; i < 4; i++){
            posisiMatriks tempPos; //temp menampung posisi neighbor yg diperiksa
            tempPos.baris = cur.pos.baris + dirY[i];
            tempPos.kolom = cur.pos.kolom + dirX[i];
            if(isValidPos(tempPos)){  //Periksa kalo posisi ini ada di dalam range matriks atau tidak
                curNeighbor = grid[tempPos.baris][tempPos.kolom];
                if(isSamePos(curNeighbor.pos, end)){  //kalo neighbor ini sama kayak posisi destinasi, pencarian berhenti
                    curNeighbor.parent = cur.pos;
                    grid[tempPos.baris][tempPos.kolom] = curNeighbor;
                    foundEnd = true; break;
                }else if(!closedSet.isInList(curNeighbor) && !curNeighbor.blocked){ // hitung nilai f kalo neighbor belum di closedlist dan neighbor bisa dilewati
                    gNew = cur.g + 1.0;
                    hNew = abs(curNeighbor.pos.kolom - end.kolom) + abs(curNeighbor.pos.baris - end.baris);
                    fNew = gNew + hNew;

                    if(curNeighbor.f == FLT_MAX || curNeighbor.f > fNew){ // Update jika f yang baru lebih kecil daripada f neighbor yg lama
                        curNeighbor.f = fNew;
                        curNeighbor.g = gNew;
                        curNeighbor.h = hNew;
                        curNeighbor.parent = cur.pos;
                        grid[tempPos.baris][tempPos.kolom] = curNeighbor;
                        openSet.push_sorted(curNeighbor);

                    }

                }
            }
        }
        // cur dimasukkan ke closed set karena sudah di evaluasi
        closedSet.push(cur);
    }

    /* --- Pencarian Path --- */
    // Keluar dari loop karena posisi endnya udah ketemu yaitu curNeighbor
    // Untuk nyari pathnya, ditrace dari posisi curNeighbor ke parentnya sampe parentnya udah ga ada lagi
    ListGrid path;
    posisiMatriks temp = curNeighbor.pos;
    while(isValidPos(grid[temp.baris][temp.kolom].parent)){
        path.push(grid[temp.baris][temp.kolom]);
        temp = grid[temp.baris][temp.kolom].parent;
    }


    /* --- Menentukan Gerakan --- */
    // Menentukan gerakan yang harus diambil bot berdasarkan posisi path berikutnya
    if(path.head == NULL){
        return NULL;
    }else if(path.head->info.pos.kolom > start.kolom){
        return KEY_RIGHT;
    }else if (path.head->info.pos.kolom < start.kolom){
        return KEY_LEFT;
    }else if(path.head->info.pos.baris > start.baris){
        return KEY_DOWN;
    }else{
        return KEY_UP;
    }
}

bool isSamePos(posisiMatriks pos1, posisiMatriks pos2){
    if((pos1.kolom == pos2.kolom) && (pos1.baris == pos2.baris)){
        return true;
    }else{
        return false;
    }
}

bool isValidPos(posisiMatriks pos){
    if((pos.baris >= 0) && (pos.baris < BARIS) && (pos.kolom >= 0) && (pos.kolom < KOLOM)){
        return true;
    }else{
        return false;
    }
}

bool isTrapped(int arr[BARIS][KOLOM], int x, int y, char spriteType){
    int baris = y/MATRIX_ELEMENT_SIZE;
    int kolom = (x + MATRIX_ELEMENT_SIZE/2)/MATRIX_ELEMENT_SIZE;
    if(spriteType == 'B'){
        return ((arr[baris][kolom] == 8) || (arr[baris][kolom] == 9));
    }else if(spriteType == 'P'){
        return (((arr[baris][kolom] == 8) || (arr[baris][kolom] == 9)) && !isFalling(arr, x, y) && isNabrak(arr, x, y, 1) && isNabrak(arr, x, y, -1));
    }else{
        return false;
    }
}
