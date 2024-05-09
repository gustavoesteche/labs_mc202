#ifndef NO_H
#define NO_H 

typedef struct no *p_no;

struct no{
    char dado;
    p_no dir, esq;
};


#endif