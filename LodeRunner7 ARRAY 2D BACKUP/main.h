#ifndef main_H
#define main_H

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>

#define MATRIX_ELEMENT_SIZE 40
#define BARIS 17
#define KOLOM 28

#define SCOREBAR 50
#define GAME_HEIGHT BARIS*MATRIX_ELEMENT_SIZE
#define GAME_WIDTH KOLOM*MATRIX_ELEMENT_SIZE

#define WINDOWS_HEIGHT GAME_HEIGHT+SCOREBAR
#define WINDOWS_WIDTH  GAME_WIDTH

#define MAX_LEVEL 5
#define FALL 1

/* ---------------------------- Struktur Data Posisi ---------------------------- */
typedef struct{
    int X;
    int Y;
}koordinat;  //koordinat/posisi sprite dalam pixel

typedef struct{
    int baris;
    int kolom;
}posisiMatriks; //posisi sprite dalam matriks

/* ---------------------------- Struktur Data Sprite ---------------------------- */
typedef struct{
    koordinat koor;
    posisiMatriks pm;
    char movement = NULL;
    int urutanAnimasi = 1;
    int urutanBom = -1;
    int lives = 3;
}spriteInfo;                //struktur data suatu sprite

typedef struct{
    void* brick;
    void* bedrock;
    void* ladder;
    void* coin;
    void* exit;
    void* rope;
}blockSprite;  // Sprite block

typedef struct{
    void* running[16];
    void* climbingLadder[2];
    void* climbingRope[4];
    void* bombing[2];
}spriteAnim;


/* ---------------------------- Struktur Data Queue Lubang ---------------------------- */
typedef struct{
    posisiMatriks pos;
    clock_t start;
    int urutan = -1;
}lubang;            //data satu lubang hasil dilempar bom

//typedef struct{
//    lubang dt_lubang[20];
//    int Count;
//    int MaxSize;
//    int Front;
//    int Back;
//}arrayQueue;            //queue alokasi statis untuk menampung data lubang

struct tElmtQueueLubang{
    lubang info;
    tElmtQueueLubang* next;
};

typedef struct{
    tElmtQueueLubang* Front = NULL;
    tElmtQueueLubang* Back = NULL;

    tElmtQueueLubang* Create_Node(lubang info){
        tElmtQueueLubang* pNew;
        pNew = (tElmtQueueLubang*) malloc(sizeof(tElmtQueueLubang));
        pNew->info = info;
        pNew->next = NULL;
        return pNew;
    }
    void enqueue(lubang info){
        if(Back == NULL){
            Back = Create_Node(info);
            Front = Back;
        }else{
            tElmtQueueLubang* pNew = Create_Node(info);
            Back->next = pNew;
            Back = pNew;
        }
    }
    lubang dequeue(){
        if(Front != NULL){
            lubang temp;
            tElmtQueueLubang* pDel = Front;

            Front = Front->next;
            if(Front == NULL) Back = NULL;

            pDel->next = NULL;
            temp = pDel->info;
            free(pDel);
            return temp;
        }
    }
}QueueLubang;

/* ---------------------------- Struktur Data Grid/Map ---------------------------- */
typedef struct{
    int info;
    posisiMatriks pos;
    double f;
    double g;
    double h;
    bool blocked;
    posisiMatriks parent;
    void show(int color){
        if(blocked){
            setfillstyle(SOLID_FILL, MAGENTA);
            rectangle(pos.kolom*MATRIX_ELEMENT_SIZE, pos.baris*MATRIX_ELEMENT_SIZE, (pos.kolom+1)*MATRIX_ELEMENT_SIZE, (pos.baris+1)*MATRIX_ELEMENT_SIZE);
            floodfill(pos.kolom*MATRIX_ELEMENT_SIZE+1, pos.baris*MATRIX_ELEMENT_SIZE+1, WHITE);
        }else{
            setfillstyle(SOLID_FILL, color);
            rectangle(pos.kolom*MATRIX_ELEMENT_SIZE, pos.baris*MATRIX_ELEMENT_SIZE, (pos.kolom+1)*MATRIX_ELEMENT_SIZE, (pos.baris+1)*MATRIX_ELEMENT_SIZE);
            floodfill(pos.kolom*MATRIX_ELEMENT_SIZE+1, pos.baris*MATRIX_ELEMENT_SIZE+1, WHITE);
        }
    }
}tElmtGrid;


typedef struct{
    int lv;
    tElmtGrid arr[BARIS][KOLOM];
    posisiMatriks exitPos;
    posisiMatriks playerPos;
    posisiMatriks botPos[5];
    int jmlBot;
}infoLevel;            //info satu level


/* ---------------------------- Struktur Data List Grid/Map ---------------------------- */
struct tElmtListGrid{
    tElmtGrid info;
    tElmtListGrid* next;
};

typedef struct{
    tElmtListGrid* head = NULL;

    tElmtListGrid* Create_Node(tElmtGrid info){
        tElmtListGrid* pNew;
        pNew = (tElmtListGrid*) malloc(sizeof(tElmtListGrid));
        pNew->info = info;
        pNew->next = NULL;
        return pNew;
    }
    void push(tElmtGrid elm){
        if(head == NULL){
            head = Create_Node(elm);
        }else{
            tElmtListGrid* pNew;
            pNew = Create_Node(elm);
            pNew->next = head;
            head = pNew;
        }
    }
    void push_sorted(tElmtGrid elm){
        if(head == NULL){
            head = Create_Node(elm);
        }else{
            tElmtListGrid* pNew;
            pNew = Create_Node(elm);
            if(head->info.f >= pNew->info.f){
                pNew->next = head;
                head = pNew;
            }else{
                tElmtListGrid* temp = head;
                while((temp->next != NULL) && (temp->next->info.f < pNew->info.f)) temp = temp->next;
                pNew->next = temp->next;
                temp->next = pNew;
            }
        }
    }
    tElmtGrid pop(tElmtGrid elm){
        tElmtListGrid* temp = head; tElmtGrid X;
        while(temp != NULL){
            if((elm.pos.kolom == temp->info.pos.kolom) && (elm.pos.baris == temp->info.pos.baris)){
                X = temp->info;
                if(head == temp){
                    head = temp->next;
                    temp->next = NULL;
                }else{
                    tElmtListGrid* pBfr = head;
                    while(pBfr->next != temp) pBfr = pBfr->next;
                    pBfr->next = temp->next;
                    temp->next = NULL;
                }
                free(temp);
                return X;
            }
            temp = temp->next;
        }
        return X;
    }
    bool isInList(tElmtGrid elm){
        tElmtListGrid* temp = head;
        while(temp != NULL){
            if((temp->info.pos.kolom == elm.pos.kolom) && (temp->info.pos.baris == elm.pos.baris))
                if(temp->info.f >= elm.f)
                    return true;
            temp = temp->next;
        }
        return false;
    }
    void show(int color){
        tElmtListGrid* temp = head;
        while(temp != NULL){
            temp->info.show(color);
            temp = temp->next;
        }
    }
}ListGrid;



/* ---------------------------- Struktur Data User ---------------------------- */
typedef struct{
    char nama[50];
    int score = 0;
}tUser;







void tampilan_exit(double wkttotal, int score);
void permainan();

#endif // main_H



