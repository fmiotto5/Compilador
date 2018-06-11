#define TKId 1

//PALAVRAS RESERVADAS
#define TKVoid 2
#define TKShort 3
#define TKInt 4
#define TKLong 5
#define TKFloat 6
#define TKDouble 7
#define TKChar 69
#define TKAsm 8
#define TKAuto 9
#define TKBreak 10
#define TKIf 11
#define TKElse 12
#define TKWhile 13
#define TKDo 14
#define TKFor 15
#define TKSwitch 16
#define TKCase 17
#define TKContinue 18
#define TKDefault 19
#define TKConst 20
#define TKEnum 21
#define TKExtern 22
#define TKGoto 23
#define TKRegister 24
#define TKReturn 25
#define TKSigned 26
#define TKUnsigned 27
#define TKSizeof 28
#define TKStatic 29
#define TKStruct 30
#define TKTypedef 31
#define TKUnion 32
#define TKVolatile 33

//CARACTERES EPSECIAIS //OPERADORES
#define TKAbrePar 34        /* ( */
#define TKFechaPar 35       /* ) */
#define TKAbreChave 36      /* { */
#define TKFechaChave 37     /* } */
#define TKAbreColchete 38   /* [ */
#define TKFechaColchete 39  /* ] */
#define TKPontoeVirg 40     /* ; */
#define TKDoisPontos 41     /* : */
#define TKVirgula 42        /* , */
#define TKAtrib 43          /* = */
#define TKMais 44           /* + */
#define TKMenos 45          /* - */
#define TKMultiplicacao 46  /* * */
#define TKDivisao 47        /* / */
#define TKRestoDivisao 48   /* % */
#define TKMaior 49          /* > */
#define TKMenor 50          /* < */
#define TKHashtag 51        /* # */

//OPERADORES REDUZIDOS
#define TKMenosIgual 52             /* -= */
#define TKMaisIgual 53              /* += */
#define TKMultiplicacaoIgual 54     /* *= */
#define TKDivisaoIgual 55           /* /= */
#define TKRestoDivisaoIgual 56      /* %= */
#define TKComparadorMaiorIgual 57   /* >= */
#define TKComparadorMenorIgual 58   /* <= */
#define TKMenosMenos 59             /* -- */
#define TKMaisMais 60               /* ++ */
#define TKComparadorIgual 61        /* == */
#define TKComparadorDiferente 62    /* != */
#define TKNegacao 63                /* ! */
#define TKTernario 64               /* ? */
#define TKShiftLeft 65              /* << */
#define TKShiftRight 66             /* >> */
#define TKOU 67                     /* || */
#define TKAND 68                    /* && */
#define TKELogico 70                /* &  */
#define TKOULogico 71               /* | */
#define TKXOR 72                    /* ^ */

//CONSTANTES
#define TKConstInt 80
#define TKConstFloat 81
#define TKConstOctal 82
#define TKConstHexa 83

//Erros
#define TKErroE 100
#define TKErroConstFloat 101
#define TKErroOU 102
#define TKErroAND 103
#define TKErroConstHexa 104

#define MAX_COD 1000

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int pos = 0;
int estado_anterior = 0;
int posColuna = 0;
int subColuna = 0;
int linha = 0;
int coluna = 0;
int tab = 0;
int tksParser[1000];
char tksParserLex[1000][20];
int posParser = 0;
int posParserLex = 0;
int tk = 0;
int doWhile = 0;
char lex[10];
int laco = 0;

int PROGC(char *PROGC_c);

int LD(char *LD_c);

int RLD(char *RLD_c);

int DEC(char *RLD_c);

int RDEC(char *RDEC_t, char *RDEC_c);

int DV(char *DV_t);

int RDV(char *RDV_t);

int TIPO(char *Tipo_t);

int RTIPOSINAL(char *RTIPOSINAL_s, char *RTIPOSINAL_t);

int RTIPOSINAL2(char *RTIPOSINAL2_s, char *RTIPOSINAL2_t);

int RTIPOSHORT(char *RTIPOSHORT_s, char *RTIPOSHORT_t);

int RTIPOLONG(char *RTIPOLONG_s, char *RTIPOLONG_t);

int RTIPOLONG2(char *RTIPOLONG2_s, char *RTIPOLONG2_t);

int DF(char *DF_c);

int LP();

int RLP();

int CORPO(char *CORPO_c);

int LCD(char *LCD_c);

int COM(char *COM_c);

int COMIF(char *COMIF_c);

int RIF(char *RIF_c);

int COMFOR(char *COMFOR_c);

int RFOR(char *RFOR_c);

int EIF(char *EIF_c, char *EIF_p);

int COMWHILE(char *COMWHILE_c);

int RWHILE(char *RWHILE_c);

int COMDOWHILE(char *COMDOWHILE_c);

int RDOWHILE(char *RDOWHILE_c);

int COMSWITCH();

int RSWITCH();

int NEXTCASE();

int E(char *E_tp, char *E_p, char *E_c);

int ELinha(char *ELinha_h, char *ELinha_s, char *ELinha_p, char *ELinha_hp, char *ELinha_sp, char *ELinha_c, char *ELinha_hc, char *ELinha_sc);

int E1(char *E1_tp, char *E1_h, char *E1_s, char *E1_p, char *E1_c);

int E2(char *E2_tp, char *E2_h, char *E2_s, char *E2_p, char *E2_c);

int E2Linha(char *E2Linha_h, char *E2Linha_s, char *E2Linha_hp, char *E2Linha_sp, char *E2Linha_hc, char *E2Linha_sc);

int E3(char *E3_tp, char *E3_p, char *E3_c);

int E3Linha(char *E3Linha_h, char *E3Linha_s, char *E3Linha_hp, char *E3Linha_sp, char *E3Linha_hc, char *E3Linha_sc);

int E4(char *E4_tp, char *E4_p, char *E4_c);

int E4Linha(char *E4Linha_h, char *E4Linha_s, char *E4Linha_hp, char *E4Linha_sp, char *E4Linha_hc, char *E4Linha_sc);

int E5(char *E5_tp, char *E5_p, char *E5_c);

int E5Linha(char *E5Linha_h, char *E5Linha_s, char *E5Linha_hp, char *E5Linha_sp, char *E5Linha_hc, char *E5Linha_sc);

int E6(char *E6_tp, char *E6_p, char *E6_c);

int E6Linha(char *E6Linha_h, char *E6Linha_s, char *E6Linha_hp, char *E6Linha_sp, char *E6Linha_hc, char *E6Linha_sc);

int E7(char *E7_tp, char *E7_p, char *E7_c);

int E7Linha(char *E7Linha_h, char *E7Linha_s, char *E7Linha_hp, char *E7Linha_sp, char *E7Linha_hc, char *E7Linha_sc);

int E8(char *E8_tp, char *E8_p, char *E8_c);

int E8Linha(char *E8Linha_h, char *E8Linha_s, char *E8Linha_hp, char *E8Linha_sp, char *E8Linha_hc, char *E8Linha_sc);

int E9(char *E9_tp, char *E9_p, char *E9_c);

int E9Linha(char *E9Linha_h, char *E9Linha_s, char *E9Linha_hp, char *E9Linha_sp, char *E9Linha_hc, char *E9Linha_sc);

int E10(char *E10_tp, char *E10_p, char *E10_c);

int E10Linha(char *E10Linha_h, char *E10Linha_s, char *E10Linha_hp, char *E10Linha_sp, char *E10Linha_hc, char *E10Linha_sc);

int E11(char *E11_tp, char *E11_p, char *E11_c);

int E11Linha(char *E11Linha_h, char *E11Linha_s, char *E11Linha_hp, char *E11Linha_sp, char *E11Linha_hc, char *E11Linha_sc);

int E12(char *E12_tp, char *E12_p, char *E12_c);

int E12Linha(char *E12Linha_h, char *E12Linha_s, char *E12Linha_hp, char *E12Linha_sp, char *E12Linha_hc, char *E12Linha_sc);

int E13(char *E13_tp, char *E13_p, char *E13_c);

int E14(char *E14_tp, char *E14_p, char *E14_c);

int RE();

struct pal_res {
    char palavra[20];
    int tk;
};
struct pal_res lista_pal[] = {{"void",      TKVoid},
                              {"short",     TKShort},
                              {"int",       TKInt},
                              {"long",      TKLong},
                              {"float",     TKFloat},
                              {"double",    TKDouble},
                              {"asm",       TKAsm},
                              {"auto",      TKAuto},
                              {"break",     TKBreak},
                              {"if",        TKIf},
                              {"else",      TKElse},
                              {"while",     TKWhile},
                              {"do",        TKDo},
                              {"for",       TKFor},
                              {"switch",    TKSwitch},
                              {"case",      TKCase},
                              {"continue",  TKContinue},
                              {"default",   TKDefault},
                              {"const",     TKConst},
                              {"enum",      TKEnum},
                              {"extern",    TKExtern},
                              {"goto",      TKGoto},
                              {"register",  TKRegister},
                              {"return",    TKReturn},
                              {"signed",    TKSigned},
                              {"unsigned",  TKUnsigned},
                              {"sizeof",    TKSizeof},
                              {"static",    TKStatic},
                              {"struct",    TKStruct},
                              {"typedef",   TKTypedef},
                              {"union",     TKUnion},
                              {"volatile",  TKVolatile},
                              {"fimtabela", TKId}
};

int palavra_reservada(char lex[]) {
    int postab = 0;
    while (strcmp("fimtabela", lista_pal[postab].palavra) != 0) {
        if (strcmp(lex, lista_pal[postab].palavra) == 0)
            return lista_pal[postab].tk;
        postab++;
    }
    return TKId;
}


int le_token(char st[], char lex[]) {
    int estado = 0, fim = 0, posl = 0;
    posColuna = pos;
    while (!fim) {
        char c = st[pos];

        lex[posl++] = c;
        switch (estado) {
            case 0:
                if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_') {
                    pos++;
                    estado = 1;
                    estado_anterior = 0;
                    break;
                }
                if (c >= '0' && c <= '9') {
                    if (c == '0') {
                        pos++;
                        estado = 8;
                        estado_anterior = 0;
                        break;
                    }
                    pos++;
                    estado = 2;
                    estado_anterior = 0;
                    break;
                }
                if (c == '.') {
                    pos++;
                    estado = 3;
                    estado_anterior = 0;
                    break;
                }
                if (c == '=') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKComparadorIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKAtrib;
                    }
                }
                if (c == '!') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKComparadorDiferente;
                    } else {
                        lex[posl] = '\0';
                        return TKNegacao;
                    }
                }
                if (c == '?') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKTernario;
                }
                if (c == '+') {
                    c = st[++pos];
                    if (c == '+') {
                        lex[posl++] = '+';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKMaisMais;
                    } else if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKMaisIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKMais;
                    }

                }
                if (c == '-') {
                    c = st[++pos];
                    if (c == '-') {
                        lex[posl++] = '-';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKMenosMenos;
                    } else if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKMenosIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKMenos;
                    }
                }
                if (c == '*') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKMultiplicacaoIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKMultiplicacao;
                    }
                }
                if (c == '/') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKDivisaoIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKDivisao;
                    }
                }
                if (c == '%') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKRestoDivisaoIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKRestoDivisao;
                    }
                }
                if (c == '|') {
                    c = st[++pos];
                    if (c == '|') {
                        lex[posl++] = '|';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKOU;
                    }
                    return TKErroOU;
                }
                if (c == '&') {
                    c = st[++pos];
                    if (c == '&') {
                        lex[posl++] = '&';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKAND;
                    }
                    return TKErroAND;
                }
                if (c == '>') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKComparadorMaiorIgual;
                    } else if (c == '>') {
                        lex[posl++] = '>';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKShiftRight;
                    } else {
                        lex[posl] = '\0';
                        return TKMaior;
                    }
                }
                if (c == '<') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKComparadorMenorIgual;
                    } else if (c == '<') {
                        lex[posl++] = '<';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKShiftLeft;
                    } else {
                        lex[posl] = '\0';
                        return TKMenor;
                    }
                }
                if (c == '(') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKAbrePar;
                }
                if (c == ')') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKFechaPar;
                }
                if (c == '{') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKAbreChave;
                }
                if (c == '}') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKFechaChave;
                }
                if (c == '[') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKAbreColchete;
                }
                if (c == ']') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKFechaColchete;
                }
                if (c == ',') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKVirgula;
                }
                if (c == ';') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKPontoeVirg;
                }
                if (c == ':') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKDoisPontos;
                }
                if (c == ' ' || c == '\n') {
                    pos++;
                    posl--;
                    posColuna = pos;
                }
                if (c == 127) {
                    pos++;
                    posl--;
                    linha++;
                    subColuna = pos;
                    posColuna = pos;
                }
                if (c == 9) {
                    tab++;
                    pos++;
                    posColuna = pos;
                    posl--;
                    subColuna -= 3;
                }
                if (c == '\0') return -1;

                break;
            case 1:
                if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_' || c >= '0' && c <= '9') {
                    pos++;
                    break;
                }
                lex[--posl] = '\0';
                estado_anterior = 1;
                return palavra_reservada(lex);

            case 2:
                if (c >= '0' && c <= '9') { //JA FOI LIDO UM NUMERO ANTERIORMENTE OU UM SINAL
                    pos++;
                    break;
                }

                if (c == '.') {
                    pos++;
                    estado = 3;
                    estado_anterior = 2;
                    break;
                }
                if (c == 'E') {
                    pos++;
                    estado = 4;
                    estado_anterior = 2;
                    break;
                }
                lex[--posl] = '\0';
                estado_anterior = 2;
                return TKConstInt;
            case 3:
                if (c >= '0' && c <= '9') {
                    pos++;
                    estado = 7;
                    break;
                } else {
                    return TKErroConstFloat;
                }

            case 4:
                if (c >= '0' && c <= '9') {
                    pos++;
                    estado = 6;
                    break;
                } else if (c == '-' || c == '+') {
                    pos++;
                    estado = 5;
                    break;
                }
                return TKErroE;

            case 5:
                if (c >= '0' && c <= '9') {
                    pos++;
                    estado = 6;
                    break;
                }
                return TKErroE;

            case 6:
                if (c >= '0' && c <= '9') {
                    pos++;
                    break;
                }
                if (estado_anterior = 2) {
                    lex[--posl] = '\0';
                    estado_anterior = 6;
                    return TKConstInt;
                } else {
                    lex[--posl] = '\0';
                    estado_anterior = 6;
                    return TKConstFloat;
                }
            case 7:
                if (c >= '0' && c <= '9') {
                    pos++;
                    break;
                }
                if (c == 'E') {
                    pos++;
                    estado = 4;
                    estado_anterior = 7;
                    break;
                }
                lex[--posl] = '\0';
                estado_anterior = 7;
                return TKConstFloat;
            case 8:
                if (c >= '0' && c <= '9') {
                    pos++;
                    break;
                }
                if (c == 'x' || c == 'X') {
                    pos++;
                    estado = 9;
                    estado_anterior = 8;
                    break;
                }
                lex[--posl] = '\0';
                return TKConstInt;
            case 9:
                if (c >= '0' && c <= '9') {
                    pos++;
                    estado_anterior = 9;
                    break;
                } else {
                    if (estado_anterior == 8)
                        return TKErroConstHexa;
                }
                lex[--posl] = '\0';
                return TKConstInt;
        }
    }
}

void getToken() {
    tk = tksParser[posParser++];
    linha = tksParser[posParser++];
    coluna = tksParser[posParser++];
    strcpy(lex, tksParserLex[posParserLex++]);
}

typedef struct TS {
    char id[10];
    char tipo[10];
    struct TS *prox;
} tabela;

tabela *ts;

void poetabsimb(char *id, char *tipo) {
    tabela *aux = (tabela *) malloc(sizeof(tabela));
    strcpy(aux->id, id);
    strcpy(aux->tipo, tipo);
    aux->prox = ts;
    ts = aux;
}

int verificaDuplicacao(char *lex, tabela *tab) {
    if (tab == NULL)
        return 1;

    if (!strcmp(tab->id, lex)) {
        printf("Variavel %s ja foi declarada\n", lex);
        printf("Erro ocorreu na linha %d, coluna %d",linha,coluna);
        exit(0);
    }

    return verificaDuplicacao(lex, tab->prox);
}

void *consultaTipo(char *id, char *Tipo, tabela *tab){
    if (tab == NULL)
        return 1;


    if (!strcmp(tab->id, id)) {
        strcpy(Tipo,tab->tipo);
    }

    return consultaTipo(id, Tipo, tab->prox);
}

void geralabel(char label[])
{
    static int numlabel=0;
    sprintf(label,"LB%03d",numlabel++);
}

void geratemp(char temp[])
{
    static int numtemp=0;
    sprintf(temp,"T%03d",numtemp++);
}

int PROGC(char *PROGC_c) { // PROGC -> LD
    char LD_c[MAX_COD];

    if (LD(LD_c)) {
        strcpy(PROGC_c, LD_c);
        return 1;
    }
    else
        return 0;
}

int LD(char *LD_c) { // LD -> DEC RLD
    char DEC_c[MAX_COD], RLD_c[MAX_COD];

    if (DEC(DEC_c)) {
        if (RLD(RLD_c)) {
            sprintf(LD_c, "%s%s\n", DEC_c, RLD_c);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int RLD(char *RLD_c) { // RLD -> LD / e
    char LD_c[MAX_COD];

    if (LD(LD_c)) {
        strcpy(RLD_c, LD_c);
        return 1;
    }
    else
        return 1;
}

int DEC(char *DEC_c) { // DEC -> TIPO{RDEC.t=TIPO.t} id{poetabsimb(id,TIPO.t)} RDEC
    char RDEC_t[10], Tipo_t[10], RDEC_c[MAX_COD];

    if (TIPO(Tipo_t)) {
        strcpy(RDEC_t, Tipo_t);
        if (tk == TKId) {
            if (verificaDuplicacao(lex,ts))
                poetabsimb(lex, Tipo_t);
            getToken();
            if (RDEC(RDEC_t, RDEC_c)) {
                strcpy(DEC_c, RDEC_c);
                return 1;
            }
            else
                return 0;
        } else {
            printf("Erro: esperava token 'id' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else
        return 0;
}

int RDEC(char *RDEC_t, char *RDEC_c) { // RDEC -> ,{DV.t=RDEC.t}DV / (DF / ; / = cte;
    char DF_c[MAX_COD];

    char DV_t[10];
    if (tk == TKVirgula) {
        strcpy(DV_t, RDEC_t);
        getToken();
        if (DV(DV_t))
            return 1;
        else
            return 0;
    } else if (tk == TKAbrePar) {
        getToken();
        if (DF(DF_c)) {
            strcpy(RDEC_c, DF_c);
            return 1;
        }
        else
            return 0;
    } else if (tk == TKPontoeVirg) {
        getToken();
        return 1;
    } else if (tk == TKAtrib) {
        getToken();
        if (tk == TKConstInt) {
            getToken();
            if (tk == TKPontoeVirg) {
                getToken();
                return 1;
            } else {
                printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else {
            printf("Erro: esperava token contante inteira na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else {
        printf("Erro: esperava token ';', ')' ou ',' na linha %d coluna %d\n", linha, coluna);
        return 0;
    }
}

int DV(char *DV_t) { // DV -> id{RDV.t=DV.t}{poetabsimb(id,DV.t)} RDV
    char RDV_t[10];
    if (tk == TKId) {
        strcpy(RDV_t, DV_t);
        if (verificaDuplicacao(lex,ts))
            poetabsimb(lex, DV_t);
        getToken();
        if (RDV(RDV_t))
            return 1;
        else
            return 0;
    } else {
        printf("Erro: esperava token 'id' na linha %d coluna %d\n", linha, coluna);
        return 0;
    }
}

int RDV(char *RDV_t) { // RDV -> ,{DV.t=RDV.t}DV / ;
    char DV_t[10];
    if (tk == TKVirgula) {
        strcpy(DV_t, RDV_t);
        getToken();
        if (DV(DV_t))
            return 1;
        else
            return 0;
    } else if (tk == TKPontoeVirg) {
        getToken();
        return 1;
    } else {
        printf("Erro: esperava token ',' ou ';' na linha %d coluna %d\n", linha, coluna);
        return 0;
    }
}

int
TIPO(char *Tipo_t) {
//    char{TIPO.t=“char”}/int{TIPO.t=“int”}/float{TIPO.t=“float”}/double{TIPO.t=“double”}/
//    signed{RTIPOSINAL.s=”signed”}RTIPOSINAL{TIPO.t=RTIPOSINAL.t} /
//    unsigned{RTIPOSINAL.s=”unsigned”}RTIPOSINAL{TIPO.t=RTIPOSINAL.t} /
//    short{RTIPOSHORT.s=”short”}RTIPOSHORT{TIPO.t=RTIPOSHORT.t} /
//    long{RTIPOLONG.s=”long”}RTIPOLONG{TIPO.t=RTIPOLONG.t}
    char RTIPOSINAL_s[10], RTIPOSHORT_s[10], RTIPOLONG_s[10], RTIPOSINAL_t[10], RTIPOSHORT_t[10], RTIPOLONG_t[10];
    if (tk == TKChar || tk == TKInt || tk == TKFloat || tk == TKDouble) {
        switch (tk) {
            case TKChar:
                strcpy(Tipo_t, "char");
                break;
            case TKInt:
                strcpy(Tipo_t, "int");
                break;
            case TKFloat:
                strcpy(Tipo_t, "float");
                break;
            case TKDouble:
                strcpy(Tipo_t, "double");
                break;
        }
        getToken();
        return 1;
    } else if (tk == TKSigned || tk == TKUnsigned) {
        switch (tk) {
            case TKSigned:
                strcpy(RTIPOSINAL_s, "signed");
                strcpy(RTIPOSINAL_t, Tipo_t);
                break;
            case TKUnsigned:
                strcpy(RTIPOSINAL_s, "unsigned");
                strcpy(RTIPOSINAL_t, Tipo_t);
                break;
        }
        getToken();
        if (RTIPOSINAL(RTIPOSINAL_s, RTIPOSINAL_t)) {
            strcpy(Tipo_t, RTIPOSINAL_t);
            return 1;
        } else
            return 0;
    } else if (tk == TKShort) {
        strcpy(RTIPOSHORT_s, "short");
        getToken();
        if (RTIPOSHORT(RTIPOSHORT_s, RTIPOSHORT_t)) {
            strcpy(Tipo_t, RTIPOSHORT_t);
            return 1;
        }
        else
            return 0;
    } else if (tk == TKLong) {
        strcpy(RTIPOLONG_s, "long");
        getToken();
        if (RTIPOLONG(RTIPOLONG_s, RTIPOLONG_t)) {
            strcpy(Tipo_t,RTIPOLONG_t);
            return 1;
        }
        else
            return 0;
    } else {
        return 0;
    }
}

int RTIPOSINAL(char *RTIPOSINAL_s, char *RTIPOSINAL_t) { //RTIPOSINAL -> char{RTIPOSINAL.t=RTIPOSINAL.s + “ char”}/
    char RTIPOSINAL2_s[10], RTIPOSINAL2_t[10];
//    int{RTIPOSINAL.t=RTIPOSINAL.s + “ int”)} /
//    short{RTIPOSINAL2.s=RTIPOSINAL.s + “ short”} RTIPOSINAL2{RTIPOSINAL.t=RTIPOSINAL2.t} /
//    long{RTIPOSINAL2.s=RTIPOSINAL.s + “ long”} RTIPOSINAL2{RTIPOSINAL.t=RTIPOSINAL2.t} / e
    if (tk == TKChar || tk == TKInt) {
        if(tk==TKChar) {
            strcat(RTIPOSINAL_s, " char");
            strcpy(RTIPOSINAL_t, RTIPOSINAL_s);
        } else if(tk == TKInt){
            strcat(RTIPOSINAL_s, " int");
            strcpy(RTIPOSINAL_t, RTIPOSINAL_s);
        }
        getToken();
        return 1;
    } else if (tk == TKShort || tk == TKLong) {
        if(tk==TKShort){
            strcat(RTIPOSINAL_s," short");
            strcpy(RTIPOSINAL2_s,RTIPOSINAL_s);
        } else if(tk==TKLong){
            strcat(RTIPOSINAL_s," long");
            strcpy(RTIPOSINAL2_s,RTIPOSINAL_s);
        }
        getToken();
        if (RTIPOSINAL2(RTIPOSINAL2_s, RTIPOSINAL2_t)) {
            strcpy(RTIPOSINAL_t,RTIPOSINAL2_t);
            return 1;
        }
        else
            return 0;
    } else
        return 1;
}

int RTIPOSINAL2(char *RTIPOSINAL2_s, char *RTIPOSINAL2_t) { //RTIPOSINAL2 -> int{RTIPOSINAL2.t=RTIPOSINAL2.s + “ int”}
    if (tk == TKInt) {
        strcat(RTIPOSINAL2_s," int");
        strcpy(RTIPOSINAL2_t,RTIPOSINAL2_s);
        getToken();
        return 1;
    } else {
        printf("Erro: esperava token 'int' na linha %d coluna %d\n", linha, coluna);
        return 0;
    }
}

int RTIPOSHORT(char *RTIPOSHORT_s, char *RTIPOSHORT_t) { //RTIPOSHORT -> int{RTIPOSHORT.t=RTIPOSHORT.s + “ int”} / e
    if (tk == TKInt) {
        strcat(RTIPOSHORT_s," int");
        strcpy(RTIPOSHORT_t,RTIPOSHORT_s);
        getToken();
        return 1;
    } else
        return 1;
}

int RTIPOLONG(char *RTIPOLONG_s, char *RTIPOLONG_t) { //RTIPOLONG -> int{RTIPOLONG.t=RTIPOLONG.s + “ int”}/
//    double{RTIPOLONG.t=RTIPOLONG.s + “ double”}/
//    long{RTIPOLONG2.s=RTIPOLONG.s + “ long”} RTIPOLONG2{RTIPOLONG.t=RTIPOLONG2.t} / e
    char RTIPOLONG2_t[10], RTIPOLONG2_s[10];

    if (tk == TKInt || tk == TKDouble) {
        if(tk==TKInt){
            strcat(RTIPOLONG_s," int");
            strcpy(RTIPOLONG_t,RTIPOLONG_s);
        } else if (tk==TKDouble){
            strcat(RTIPOLONG_s," char");
            strcpy(RTIPOLONG_t,RTIPOLONG_s);
        }
        getToken();
        return 1;
    } else if (tk == TKLong) {
        strcat(RTIPOLONG_s," double");
        strcpy(RTIPOLONG2_s,RTIPOLONG_s);
        getToken();
        if (RTIPOLONG2(RTIPOLONG2_s, RTIPOLONG2_t)) {
            strcpy(RTIPOLONG_t,RTIPOLONG2_t);
            return 1;
        }
        else
            return 0;
    } else
        return 1;
}

int RTIPOLONG2(char *RTIPOLONG2_s, char *RTIPOLONG2_t   ) { //RTIPOLONG2 -> int{RTIPOLONG2.t=RTIPOLONG2.s + “ int”}/ e
    if (tk == TKInt) {
        strcat(RTIPOLONG2_s, " int");
        strcpy(RTIPOLONG2_t,RTIPOLONG2_s);
        getToken();
        return 1;
    } else
        return 1;
}

int DF(char *DF_c) { // DF -> LP){CORPO}
    char CORPO_c[MAX_COD];

    if (LP()) {
        if (tk == TKFechaPar) {
            getToken();
            if (tk == TKAbreChave) {
                getToken();
                if (CORPO(CORPO_c)) {
                    if (tk == TKFechaChave) {
                        strcpy(DF_c, CORPO_c);
                        getToken();
                        return 1;
                    } else {
                        printf("Erro: esperava token '}' na linha %d coluna %d\n", linha, coluna);
                        return 0;
                    }
                } else
                    return 0;
            } else {
                printf("Erro: esperava token '{' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else {
            printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else
        return 0;
}

int LP() { //LP -> TIPO id{poetabsimb(id,TIPO.t)} RLP / e
    char TIPO_t[10];

    if (TIPO(TIPO_t)) {
        if (tk == TKId) {
            if (verificaDuplicacao(lex,ts))
                poetabsimb(lex, TIPO_t);
            getToken();
            if (RLP())
                return 1;
            else
                return 0;
        } else {
            printf("Erro: esperava token 'id' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else
        return 1;
}

int RLP() { //RLP -> ,TIPO id{poetabsimb(id,TIPO.t)} RLP / e
    char TIPO_t[10];

    if (tk == TKVirgula) {
        getToken();
        if (TIPO(TIPO_t)) {
            if (tk == TKId) {
                if (verificaDuplicacao(lex,ts))
                    poetabsimb(lex, TIPO_t);
                getToken();
                if (RLP())
                    return 1;
                else
                    return 0;
            } else {
                printf("Erro: esperava token 'id' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else
            return 0;
    } else
        return 1;
}

int CORPO(char *CORPO_c) { //CORPO -> LCD
    char LCD_c[MAX_COD];

    if (LCD(LCD_c)) {
        strcpy(CORPO_c, LCD_c);
        return 1;
    }
    else
        return 0;
}

int LCD(char *LCD_c) { //LCD -> COM LCD / TIPO{DV.t=TIPO.t} DV LCD / e
    char DV_t[10], TIPO_t[10], COM_c[MAX_COD], LCDLinha_c[MAX_COD];

    strcpy(LCDLinha_c,"");

    if (COM(COM_c)) {
        if (LCD(LCDLinha_c)) {
            sprintf(LCD_c, "%s%s", COM_c, LCDLinha_c);
            return 1;
        }
        else
            return 0;
    } else if (TIPO(TIPO_t)) {
        strcpy(DV_t,TIPO_t);
        if (DV(DV_t)) {
            if (LCD(LCDLinha_c)) {
                strcpy(LCD_c, LCDLinha_c);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else
        return 1;
}

int COM(char *COM_c) { //COM -> E; / COMWHILE / COMDOWHILE / COMIF / COMFOR / COMSWITCH / return; / break; / {LCD} / TIPO{RDEC.t=TIPO.t} id{poetabsimb(id,TIPO.t)} RDEC
    char RDEC_t[10], TIPO_t[10], E_tp[10], E_p[10], E_c[MAX_COD], LCD_c[MAX_COD], RDEC_c[MAX_COD];
    char COMWHILE_c[MAX_COD], COMFOR_c[MAX_COD], COMDOWHILE_c[MAX_COD], COMIF_c[MAX_COD];

    if (E(E_tp, E_p, E_c)) {
        if (tk == TKPontoeVirg) {
            strcpy(COM_c, E_c);
            getToken();
            return 1;
        } else {
            printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (COMWHILE(COMWHILE_c)) {
        strcpy(COM_c, COMWHILE_c);
        return 1;
    }
    else if (COMDOWHILE(COMDOWHILE_c)) {
        strcpy(COM_c, COMDOWHILE_c);
        return 1;
    }
    else if (COMIF(COMIF_c)) {
        strcpy(COM_c,COMIF_c);
        return 1;
    }
    else if (COMFOR(COMFOR_c)) {
        strcpy(COM_c, COMFOR_c);
        return 1;
    }
    else if (COMSWITCH())
        return 1;
    else if (tk == TKReturn) {
        getToken();
        if (tk == TKPontoeVirg) {
            getToken();
            return 1;
        } else {
            printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (tk == TKBreak) {
        if(laco == 0) {
            printf("Erro: comando break fora de laco de repeticao");
            exit(0);
        }
        getToken();
        if (tk == TKPontoeVirg) {
            getToken();
            return 1;
        } else {
            printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    }else if (tk == TKContinue) {
        if(laco == 0) {
            printf("Erro: comando continue fora de laco de repeticao");
            exit(0);
        }
        getToken();
        if (tk == TKPontoeVirg) {
            getToken();
            return 1;
        } else {
            printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (tk == TKAbreChave) {
        getToken();
        if (LCD(LCD_c)) {
            if (tk == TKFechaChave) {
                strcpy(COM_c, LCD_c);
                getToken();
                return 1;
            } else {
                printf("Erro: esperava token '}' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else
            return 0;
    } else if (TIPO(TIPO_t)) { // TIPO id RDEC
        strcpy(RDEC_t,TIPO_t);
        if (tk == TKId) {
            if (verificaDuplicacao(lex,ts))
                poetabsimb(lex, TIPO_t);
            getToken();
            if (RDEC(RDEC_t, RDEC_c)) {
                strcpy(COM_c, RDEC_c);
                return 1;
            }
            else
                return 0;
        } else {
            printf("Erro: esperava token 'id' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else {
        return 0;
    }
}

int COMIF(char *COMIF_c) { //COMIF -> if(E)COM RIF
    char E_tp[10], E_p[MAX_COD],E_c[MAX_COD], COM_c[MAX_COD];
    char RIF_c[MAX_COD];
    char labelelse[10],labelfim[10];

    strcpy(RIF_c,"");

    if (tk == TKIf) {
        getToken();
        if (tk == TKAbrePar) {
            getToken();
            if (E(E_tp, E_p, E_c)) {
                if (tk == TKFechaPar) {
                    getToken();
                    if (COM(COM_c)) {
                        if (RIF(RIF_c)) {
                            geralabel(labelelse);
                            geralabel(labelfim);
                            if(strcmp(RIF_c,""))
                                sprintf(COMIF_c,"%s\tif %s==0 goto %s\n%s\tgoto %s\n%s:\n%s%s:\n",E_c,E_p,labelelse,COM_c,labelfim,labelelse,RIF_c,labelfim);
                            else
                                sprintf(COMIF_c,"%s\tif %s==0 goto %s\n%s%s:\n",E_c,E_p,labelfim,COM_c,labelfim);
                            return 1;
                        }
                        else
                            return 0;
                    } else
                        return 0;
                } else {
                    printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            } else
                return 0;
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else {
        return 0;
    }
}

int RIF(char *RIF_c) { //RIF -> else COM / e
    char COM_c[MAX_COD];

    if (tk == TKElse) {
        getToken();
        if (COM(COM_c)) {
            strcpy(RIF_c,COM_c);
            return 1;
        }
        else
            return 0;
    } else
        return 1;
}

int COMFOR(char *COMFOR_c) { //COMFOR -> for(EIF;EIF;EIF)COM RFOR
    char COM_c[MAX_COD], RFOR_c[MAX_COD];
    char EIF1_c[MAX_COD], EIF2_c[MAX_COD], EIF3_c[MAX_COD];
    char EIF1_p[MAX_COD], EIF2_p[MAX_COD], EIF3_p[MAX_COD];
    char labellaco[MAX_COD],labelfim[MAX_COD];

    if (tk == TKFor) {
        laco = 1;
        getToken();
        if (tk == TKAbrePar) {
            getToken();
            if (EIF(EIF1_c, EIF1_p)) {
                if (tk == TKPontoeVirg) {
                    getToken();
                    if (EIF(EIF2_c, EIF2_p)) {
                        if (tk == TKPontoeVirg) {
                            getToken();
                            if (EIF(EIF3_c, EIF3_p)) {
                                if (tk == TKFechaPar) {
                                    getToken();
                                    if (COM(COM_c)) {
                                        laco = 0;
                                        if (RFOR(RFOR_c)) {
                                            geralabel(labellaco);
                                            geralabel(labelfim);
                                            sprintf(COMFOR_c, "%s%s:\n%s\tif %s == 0 goto %s\n%s%s\tgoto %s\n%s:\n%s", EIF1_c,
                                                    labellaco,
                                                    EIF2_c, EIF2_p, labelfim, COM_c, EIF3_c, labellaco, labelfim, RFOR_c);
                                            return 1;
                                        }
                                        else
                                            return 0;
                                    } else
                                        return 0;
                                } else {
                                    printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                                    return 0;
                                }
                            } else
                                return 0;
                        } else {
                            printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
                            return 0;
                        }
                    } else
                        return 0;
                } else {
                    printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            } else
                return 0;
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else
        return 0;
}

int RFOR(char *RFOR_c) { //RFOR -> COM / e
    char COM_c[MAX_COD];

    if (COM(COM_c)) {
        strcpy(RFOR_c, COM_c);
        return 1;
    }
    else
        return 1;
}

int EIF(char *EIF_c, char *EIF_p) { //EIF -> E / e
    char E_tp[10], E_p[MAX_COD],E_c[MAX_COD];   ;

    if (E(E_tp, E_p, E_c)) {
        strcpy(EIF_c, E_c);
        strcpy(EIF_p, E_p);
        return 1;
    }
    else
        return 1;
}

int COMWHILE(char *COMWHILE_c) { //COMWHILE -> while(E)COM RWHILE
    char E_tp[10], E_p[MAX_COD],E_c[MAX_COD], COM_c[MAX_COD], RWHILE_c[MAX_COD];
    char labelinicio[10],labelfim[10];

    if (tk == TKWhile && doWhile != 1) {
        laco = 1;
        getToken();
        if (tk == TKAbrePar) {
            getToken();
            if (E(E_tp, E_p, E_c)) {
                if (tk == TKFechaPar) {
                    getToken();
                    if (COM(COM_c)) {
                        if (RWHILE(RWHILE_c)) {
                            geralabel(labelinicio);
                            geralabel(labelfim);
                            sprintf(COMWHILE_c,"%s:\n%s\tif %s==0 goto %s\n%s\tgoto %s\n%s:\n%s",labelinicio,E_c,E_p,labelfim,COM_c,labelinicio,labelfim,RWHILE_c);
                            laco = 0;
                            return 1;
                        }
                        else
                            return 0;
                    } else
                        return 0;
                } else {
                    printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            } else
                return 0;
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else {
        return 0;
    }
}

int RWHILE(char *RWHILE_c) { //RWHILE -> COM / e
    char COM_c[MAX_COD];

    if (COM(COM_c)) {
        strcpy(RWHILE_c, COM_c);
        return 1;
    }
    else
        return 1;
}

int COMDOWHILE(char *COMDOWHILE_c) { //COMDOWHILE -> do COM RDOWHILE while(E);
    char E_tp[10], E_p[MAX_COD], E_c[MAX_COD], COM_c[MAX_COD], RDOWHILE_c[MAX_COD];
    char label[10];

    if (tk == TKDo) {
        laco = 1;
        doWhile = 1;
        getToken();
        if (COM(COM_c)) {
            if (RDOWHILE(RDOWHILE_c)) {
                if (tk == TKWhile) {
                    getToken();
                    if (tk == TKAbrePar) {
                        getToken();
                        if (E(E_tp, E_p, E_c)) {
                            if (tk == TKFechaPar) {
                                getToken();
                                if (tk == TKPontoeVirg) {
                                    getToken();
                                    doWhile = 0;
                                    geralabel(label);
                                    sprintf(COMDOWHILE_c,"%s:\n%s%s\tif %s==1 goto %s\n%s",label,COM_c,E_c,E_p,label,RDOWHILE_c);
                                    laco = 0;
                                    return 1;
                                } else {
                                    printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
                                }
                            } else {
                                printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                                return 0;
                            }
                        } else
                            return 0;
                    } else {
                        printf("Erro: esperava token '(' na linha %d coluna %d\n", linha, coluna);
                        return 0;
                    }
                } else {
                    printf("Erro: esperava token 'while' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            } else
                return 0;
        } else
            return 0;
    } else {
        return 0;
    }
}

int RDOWHILE(char *RDOWHILE_c) { //RDOWHILE -> COM / e
    char COM_c[MAX_COD];

    if (COM(COM_c)) {
        strcpy(RDOWHILE_c, COM_c);
        return 1;
    }
    else
        return 1;
}

int COMSWITCH() { //COMSWITCH -> switch(E) RSWITCH
    char E_tp[10], E_p[MAX_COD],E_c[MAX_COD];

    if (tk == TKSwitch) {
        getToken();
        if (tk == TKAbrePar) {
            getToken();
            if (E(E_tp, E_p, E_c)) {
                if (tk == TKFechaPar) {
                    getToken();
                    if (RSWITCH())
                        return 1;
                    else
                        return 0;
                } else {
                    printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            } else
                return 0;
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else {
        return 0;
    }
}

int RSWITCH() { //RSWITCH -> {case cte: COM NEXTCASE} / case cte: COM / default: COM
    char COM_c[MAX_COD];

    if (tk == TKAbreChave) {
        getToken();
        if (tk == TKCase) {
            getToken();
            if (tk == TKConstInt) {
                getToken();
                if (tk == TKDoisPontos) {
                    getToken();
                    if (COM(COM_c)) {
                        if (NEXTCASE()) {
                            if (tk == TKFechaChave) {
                                getToken();
                                return 1;
                            } else {
                                printf("Erro: esperava token '}' na linha %d coluna %d\n", linha, coluna);
                                return 0;
                            }
                        } else
                            return 0;
                    } else
                        return 0;
                } else {
                    printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            } else {
                printf("Erro: esperava constante inteira na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else {
            printf("Erro: esperava token 'case' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (tk == TKCase) { // case(cte): COM
        getToken();
        if (tk == TKConstInt) {
            getToken();
            if (tk == TKDoisPontos) {
                getToken();
                if (COM(COM_c))
                    return 1;
                else
                    return 0;
            } else {
                printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else {
            printf("Erro: esperava constante inteira na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (tk == TKDefault) { // default: COM
        getToken();
        if (tk == TKDoisPontos) {
            getToken();
            if (COM(COM_c))
                return 1;
            else
                return 0;
        } else {
            printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else {
        printf("Erro: esperava token '{', 'case' ou 'default' na linha %d coluna %d\n", linha, coluna);
        return 0;
    }
}

int NEXTCASE() { //NEXTCASE -> case cte: COM NEXTCASE/ default: COM / e
    char COM_c[MAX_COD];

    if (tk == TKCase) {
        getToken();
        if (tk == TKConstInt) {
            getToken();
            if (tk == TKDoisPontos) {
                getToken();
                if (COM(COM_c)) {
                    if (NEXTCASE())
                        return 1;
                    else
                        return 0;
                } else
                    return 0;
            } else {
                printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else {
            printf("Erro: esperava constante inteira na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (tk == TKDefault) { // default: COM
        getToken();
        if (tk == TKDoisPontos) {
            getToken();
            if (COM(COM_c))
                return 1;
            else
                return 0;
        } else {
            printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else
        return 1;
}

int E(char *E_tp, char *E_p, char *E_c) { // E -> E1{E'.h = E1.tp; E'.hp = E1.p;} E' {E.tp = E'.s; E.p = E'.sp; E.c = E'.sc}
    char ELinha_h[10], ELinha_s[10], ELinha_c[MAX_COD], ELinha_p[10],ELinha_hp[10], ELinha_hc[MAX_COD], ELinha_sp[10], ELinha_sc[MAX_COD];
    char E1_tp[10], E1_h[10], E1_s[10], E1_p[10], E1_c[MAX_COD];

    if (E1(E1_tp, E1_h, E1_s, E1_p, E1_c)) {
        strcpy(ELinha_h, E1_tp);
        strcpy(ELinha_hp, E1_p);
        strcpy(ELinha_hc, E1_c);
        if (ELinha(ELinha_h, ELinha_s, ELinha_p, ELinha_hp, ELinha_sp, ELinha_c, ELinha_hc, ELinha_sc)) {
            strcpy(E_tp, ELinha_s);
            strcpy(E_p, ELinha_sp);
            strcpy(E_c, ELinha_sc);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int ELinha(char *ELinha_h, char *ELinha_s, char *ELinha_p, char *ELinha_hp, char *ELinha_sp, char *ELinha_c, char *ELinha_hc, char *ELinha_sc) { // E' -> ,E1{E'2.h=E1.tp} E'{E'.s=E'2.s; E'.p = E'2.p; E'.c = E1.c + E'2.c} / e{E'.s = E'.h; E'.sp = E'.hp; E'.sc = E'.hc}
    char ELinha2_sp[10], ELinha2_sc[MAX_COD], ELinha2_hp[10], ELinha2_hc[MAX_COD];
    char ELinha2_h[10], ELinha2_s[10], ELinha2_p[10], ELinha2_c[MAX_COD];
    char E1_tp[10], E1_h[10], E1_s[10], E1_p[10], E1_c[MAX_COD];

    if (tk == TKVirgula) {
        getToken();
        if (E1(E1_tp, E1_h, E1_s, E1_p, E1_c)) {
            strcpy(ELinha2_h, E1_tp);
            if (ELinha(ELinha2_h, ELinha2_s, ELinha2_p, ELinha2_hp, ELinha2_sp, ELinha2_c, ELinha2_hc, ELinha2_sc)) {
                strcpy(ELinha_s,ELinha2_s);
                strcpy(ELinha_p, ELinha2_p);
                sprintf(ELinha_c, "%s %s", E1_c, ELinha2_c);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else {
        strcpy(ELinha_s,ELinha_h);
        strcpy(ELinha_sp, ELinha_hp);
        strcpy(ELinha_sc, ELinha_hc);
        return 1;
    }
}

int E1(char *E1_tp, char *E1_h, char *E1_s, char *E1_p, char *E1_c) { // E1 -> E2 = {E1'.h = E2.tp}E1{E1.tp = E1'.s} / E2 *= {E1'.h = E2.tp}E1{E1.tp = E1'.s} / E2 ÷= {E1'.h = E2.tp}E1{E1.tp = E1'.s}  / E2 %= {E1'.h = E2.tp}E1{E1.tp = E1'.s} / E2 +={E1'.h = E2.tp} E1{E1.tp = E1'.s}  / E2 -={E1'.h = E2.tp} E1{E1.tp = E1'.s}  / E2{E1.tp = E2.tp}
    char E1Linha_h[10], E1Linha_s[10], E1Linha_tp[10], E1Linha_p[10], E1Linha_c[MAX_COD];
    char E2_tp[10], E2_h[10], E2_s[10], E2_p[10], E2_c[MAX_COD];

    if (E2(E2_tp, E2_h, E2_s, E2_p, E2_c)) {
        if (tk == TKAtrib) {
            strcpy(E1Linha_h,E2_tp);
            getToken();
            if (E1(E1Linha_tp, E1Linha_h, E1Linha_s, E1Linha_p, E1Linha_c)) {
                strcpy(E1_tp, E1Linha_s);
                strcpy(E1_p, E2_p);
                sprintf(E1_c, "%s\t%s = %s\n", E1Linha_c, E2_p, E1Linha_p);
                return 1;
            }
            else
                return 0;
        } else if (tk == TKMultiplicacaoIgual) {
            strcpy(E1Linha_h,E2_tp);
            getToken();
            if (E1(E1Linha_tp, E1Linha_h, E1Linha_s, E1Linha_p, E1Linha_c)) {
                strcpy(E1_tp, E1Linha_s);
                strcpy(E1_p, E2_p);
                sprintf(E1_c, "%s\t%s = %s * %s\n", E1Linha_c, E2_p, E2_p, E1Linha_p);
                return 1;
            }
            else
                return 0;
        } else if (tk == TKDivisaoIgual) {
            strcpy(E1Linha_h,E2_tp);
            getToken();
            if (E1Linha_tp, E1Linha_h, E1Linha_s, E1Linha_p, E1Linha_c) {
                strcpy(E1_tp, E1Linha_s);
                strcpy(E1_p, E2_p);
                sprintf(E1_c, "%s\t%s = %s / %s\n", E1Linha_c, E2_p, E2_p, E1Linha_p);
                return 1;
            }
            else
                return 0;
        } else if (tk == TKRestoDivisaoIgual) {
            strcpy(E1Linha_h,E2_tp);
            getToken();
            if (E1(E1Linha_tp, E1Linha_h, E1Linha_s, E1Linha_p, E1Linha_c)) {
                strcpy(E1_tp, E1Linha_s);
                strcpy(E1_p, E2_p);
                sprintf(E1_c, "%s\t%s = %s %c %s\n", E1Linha_c, E2_p, E2_p, 37, E1Linha_p);
                return 1;
            }
            else
                return 0;
        } else if (tk == TKMaisIgual) {
            strcpy(E1Linha_h,E2_tp);
            getToken();
            if (E1(E1Linha_tp, E1Linha_h, E1Linha_s, E1Linha_p, E1Linha_c)) {
                strcpy(E1_tp, E1Linha_s);
                strcpy(E1_p, E2_p);
                sprintf(E1_c, "%s\t%s = %s + %s\n", E1Linha_c, E2_p, E2_p, E1Linha_p);
                return 1;
            }
            else
                return 0;
        } else if (tk == TKMenosIgual) {
            strcpy(E1Linha_h,E2_tp);
            getToken();
            if (E1(E1Linha_tp, E1Linha_h, E1Linha_s, E1Linha_p, E1Linha_c)) {
                strcpy(E1_tp, E1Linha_s);
                strcpy(E1_p, E2_p);
                sprintf(E1_c, "%s\t%s = %s - %s\n", E1Linha_c, E2_p, E2_p, E1Linha_p);
                return 1;
            }
            else
                return 0;
        } else {
            strcpy(E1_tp, E2_tp);
            strcpy(E1_p, E2_p);
            strcpy(E1_c, E2_c);
            return 1;
        }
    }
}

int E2(char *E2_tp, char *E2_h, char *E2_s, char *E2_p, char *E2_c) { // E2 -> E3{E2'.h = E3.tp}E2' {E2.tp = E2'.s}
    char E2Linha_h[10], E2Linha_s[10], E2Linha_p[10], E2Linha_hp[10], E2Linha_sp[10], E2Linha_c[MAX_COD], E2Linha_hc[MAX_COD], E2Linha_sc[MAX_COD];
    char E3_tp[10], E3_p[10], E3_c[MAX_COD];

    if (E3(E3_tp, E3_p, E3_c)) {
        strcpy(E2Linha_h, E3_tp);
        strcpy(E2Linha_hp, E3_p);
        strcpy(E2Linha_hc, E3_c);
        if (E2Linha(E2Linha_h, E2Linha_s, E2Linha_hp, E2Linha_sp, E2Linha_hc, E2Linha_sc)) {
            strcpy(E2_tp, E2Linha_s);
            strcpy(E2_p, E2Linha_sp);
            strcpy(E2_c, E2Linha_sc );
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int E2Linha(char *E2Linha_h, char *E2Linha_s, char *E2Linha_hp, char *E2Linha_sp, char *E2Linha_hc, char *E2Linha_sc) { // E2' -> ? E2 : E2 E2' / e{E2'.s = E2'.h}
    char E2_tp[10], E2_h[10], E2_s[10], E2_p[10], E2_c[MAX_COD];
    char E2Linha2_h[10], E2Linha2_s[10], E2Linha2_hp[10], E2Linha2_sp[10], E2Linha2_hc[MAX_COD], E2Linha2_sc[MAX_COD];

    if (tk == TKTernario) {
        getToken();
        if (E2(E2_tp, E2_h, E2_s, E2_p, E2_c)) {
            if (tk == TKDoisPontos) {
                getToken();
                if (E2(E2_tp, E2_h, E2_s, E2_p, E2_c)) {
                    if (E2Linha(E2Linha2_h, E2Linha2_s, E2Linha2_hp, E2Linha2_sp, E2Linha2_hc, E2Linha2_sc))
                        return 1;
                    else
                        return 0;
                } else
                    return 0;
            } else {
                printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else
            return 0;
    } else {
        strcpy(E2Linha_s, E2Linha_h);
        strcpy(E2Linha_sp, E2Linha_hp);
        strcpy(E2Linha_sc, E2Linha_hc);
        return 1;
    }
}

int E3(char *E3_tp, char *E3_p, char *E3_c) { // E3 -> E4 {E3'.h = E4.tp}E3' {E3.tp = E3'.s}
    char E3Linha_h[10], E3Linha_s[10], E3Linha_hp[10], E3Linha_sp[10], E3Linha_hc[MAX_COD], E3Linha_sc[MAX_COD];
    char E4_tp[10], E4_p[10], E4_c[MAX_COD];

    if (E4(E4_tp, E4_p, E4_c)) {
        strcpy(E3Linha_h,E4_tp);
        strcpy(E3Linha_hp, E4_p);
        strcpy(E3Linha_hc, E4_c);
        if (E3Linha(E3Linha_h, E3Linha_s, E3Linha_hp, E3Linha_sp, E3Linha_hc, E3Linha_sc)) {
            strcpy(E3_tp, E3Linha_s);
            strcpy(E3_p, E3Linha_sp);
            strcpy(E3_c, E3Linha_sc);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int E3Linha(char *E3Linha_h, char *E3Linha_s, char *E3Linha_hp, char *E3Linha_sp, char *E3Linha_hc, char *E3Linha_sc) { // E3' -> || E4{E3'2.h=tint;} E3'{E3'.s=E3'2.s} / e{E3'.s = E3'.h}
    char E3Linha2_h[10], E3Linha2_s[10], E3Linha2_hp[10], E3Linha2_sp[10], E3Linha2_hc[MAX_COD], E3Linha2_sc[MAX_COD];
    char E4_tp[10], E4_p[10], E4_c[MAX_COD];

    if (tk == TKOU) {
        getToken();
        if (E4(E4_tp, E4_p, E4_c)) {
            strcpy(E3Linha2_h,"int");
            geratemp(E3Linha2_hp);
            sprintf(E3Linha2_hc, "%s%s\t%s = %s || %s\n", E3Linha_hc, E4_c, E3Linha2_hp, E3Linha_hp, E4_p);
            if (E3Linha(E3Linha2_h, E3Linha2_s, E3Linha2_hp, E3Linha2_sp, E3Linha2_hc, E3Linha2_sc)) {
                strcpy(E3Linha_s,E3Linha2_s);
                strcpy(E3Linha_sp, E3Linha2_sp);
                strcpy(E3Linha_sc, E3Linha2_sc);
                return 1;
            }
        } else
            return 0;
    } else {
        strcpy(E3Linha_s, E3Linha_h);
        strcpy(E3Linha_sp, E3Linha_hp);
        strcpy(E3Linha_sc, E3Linha_hc);
        return 1;
    }
}

int E4(char *E4_tp, char *E4_p, char *E4_c) { //E4 -> E5 {E4'.h = E5.tp}E4' {E4.tp = E4'.s}
    char E4Linha_h[10], E4Linha_s[10], E4Linha_hp[10], E4Linha_sp[10], E4Linha_hc[MAX_COD], E4Linha_sc[MAX_COD];
    char E5_tp[10], E5_p[10], E5_c[MAX_COD];

    if (E5(E5_tp, E5_p, E5_c)) {
        strcpy(E4Linha_h, E5_tp);
        strcpy(E4Linha_hp, E5_p);
        strcpy(E4Linha_hc, E5_c);
        if (E4Linha(E4Linha_h, E4Linha_s, E4Linha_hp, E4Linha_sp, E4Linha_hc, E4Linha_sc)) {
            strcpy(E4_tp, E4Linha_s);
            strcpy(E4_p, E4Linha_sp);
            strcpy(E4_c, E4Linha_sc);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int E4Linha(char *E4Linha_h, char *E4Linha_s, char *E4Linha_hp, char *E4Linha_sp, char *E4Linha_hc, char *E4Linha_sc) { // E4' -> && E5{E4'2.h=tint;} E4' {E4'.s=E4'2.s}/ e{E4'.s = E4'.h}
    char E4Linha2_h[10], E4Linha2_s[10], E4Linha2_hp[10], E4Linha2_sp[10], E4Linha2_hc[MAX_COD], E4Linha2_sc[MAX_COD];
    char E5_tp[10], E5_p[10], E5_c[MAX_COD];

    if (tk == TKAND) {
        getToken();
        if (E5(E5_tp, E5_p, E5_c)) {
            strcpy(E4Linha2_h, "int");
            geratemp(E4Linha2_hp);
            sprintf(E4Linha2_hc, "%s%s\t%s = %s && %s\n", E4Linha_hc, E5_c, E4Linha2_hp, E4Linha_hp, E5_p);
            if (E4Linha(E4Linha2_h, E4Linha2_s, E4Linha2_hp, E4Linha2_sp, E4Linha2_hc, E4Linha2_sc)) {
                strcpy(E4Linha_s, E4Linha2_s);
                strcpy(E4Linha_sp, E4Linha2_sp);
                strcpy(E4Linha_sc, E4Linha2_sc);
                return 1;
            } else
                return 0;
        } else
            return 0;
    } else{
        strcpy(E4Linha_s, E4Linha_h);
        strcpy(E4Linha_sp, E4Linha_hp);
        strcpy(E4Linha_sc, E4Linha_hc);
        return 1;
    }
}

int E5(char *E5_tp, char *E5_p, char *E5_c) { // E5 -> E6 {E5'.h = E6.tp}E5' {E5.tp = E5'.s}
    char E6_tp[10], E6_p[10], E6_c[MAX_COD];
    char E5Linha_h[10], E5Linha_s[10], E5Linha_hp[10], E5Linha_sp[10], E5Linha_hc[MAX_COD], E5Linha_sc[MAX_COD];

    if (E6(E6_tp, E6_p, E6_c)) {
        strcpy(E5Linha_h, E6_tp);
        strcpy(E5Linha_hp, E6_p);
        strcpy(E5Linha_hc, E6_c);
        if (E5Linha(E5Linha_h, E5Linha_s, E5Linha_hp, E5Linha_sp, E5Linha_hc, E5Linha_sc)) {
            strcpy(E5_tp, E5Linha_s);
            strcpy(E5_p, E5Linha_sp);
            strcpy(E5_c, E5Linha_sc);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int E5Linha(char *E5Linha_h, char *E5Linha_s, char *E5Linha_hp, char *E5Linha_sp, char *E5Linha_hc, char *E5Linha_sc) { // E5' -> | E6{E5'2.h=tint;} E5'{E5'.s=E5'2.s}  / e{E5'.s = E5'.h}
    char E6_tp[10], E6_p[10], E6_c[MAX_COD];
    char E5Linha2_h[10], E5Linha2_s[10], E5Linha2_hp[10], E5Linha2_sp[10], E5Linha2_hc[MAX_COD], E5Linha2_sc[MAX_COD];

    if (tk == TKOULogico) {
        getToken();
        if (E6(E6_tp, E6_p, E6_c)) {
            strcpy(E5Linha2_h, "int");
            geratemp(E5Linha2_hp);
            sprintf(E5Linha2_hc, "%s%s\t%s = %s | %s\n", E5Linha_hc, E6_c, E5Linha2_hp, E5Linha_hp, E6_p);
            if (E5Linha(E5Linha2_h, E5Linha2_s, E5Linha2_hp, E5Linha2_sp, E5Linha2_hc, E5Linha2_sc)) {
                strcpy(E5Linha_s, E5Linha2_s);
                strcpy(E5Linha_sp, E5Linha2_sp);
                strcpy(E5Linha_sc, E5Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else {
        strcpy(E5Linha_s, E5Linha_h);
        strcpy(E5Linha_sp, E5Linha_hp);
        strcpy(E5Linha_sc, E5Linha_hc);
        return 1;
    }
}

int E6(char *E6_tp, char *E6_p, char *E6_c) { // E6 -> E7 {E6'.h = E7.tp}E6' {E6.tp = E6'.s}
    char E7_tp[10], E7_p[10], E7_c[MAX_COD];
    char E6Linha_h[10], E6Linha_s[10], E6Linha_hp[10], E6Linha_sp[10], E6Linha_hc[MAX_COD], E6Linha_sc[MAX_COD];

    if (E7(E7_tp, E7_p, E7_c)) {
        strcpy(E6Linha_h, E7_tp);
        strcpy(E6Linha_hp, E7_p);
        strcpy(E6Linha_hc, E7_c);
        if (E6Linha(E6Linha_h, E6Linha_s, E6Linha_hp, E6Linha_sp, E6Linha_hc, E6Linha_sc)) {
            strcpy(E6_tp, E6Linha_s);
            strcpy(E6_p, E6Linha_sp);
            strcpy(E6_c, E6Linha_sc);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int E6Linha(char *E6Linha_h, char *E6Linha_s, char *E6Linha_hp, char *E6Linha_sp, char *E6Linha_hc, char *E6Linha_sc) { // E6' -> ^ E7{E6'2.h=tint} E6'{E6'.s=E6'2.s}  / e{E6'.s = E6'.h}
    char E7_tp[10], E7_p[10], E7_c[MAX_COD];
    char E6Linha2_h[10], E6Linha2_s[10], E6Linha2_hp[10], E6Linha2_sp[10], E6Linha2_hc[MAX_COD], E6Linha2_sc[MAX_COD];

    if (tk == TKXOR) {
        getToken();
        if (E7(E7_tp, E7_p, E7_c)) {
            strcpy(E6Linha2_h, "int");
            geratemp(E6Linha2_hp);
            sprintf(E6Linha2_hc, "%s%s\t%s = %s ^ %s\n", E6Linha_hc, E7_c, E6Linha2_hp, E6Linha_hp, E7_p);
            if (E6Linha(E6Linha2_h, E6Linha2_s, E6Linha2_hp, E6Linha2_sp, E6Linha2_hc, E6Linha2_sc)) {
                strcpy(E6Linha_s, E6Linha2_s);
                strcpy(E6Linha_sp, E6Linha2_sp);
                strcpy(E6Linha_sc, E6Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else {
        strcpy(E6Linha_s, E6Linha_h);
        strcpy(E6Linha_sp, E6Linha_hp);
        strcpy(E6Linha_sc, E6Linha_hc);
        return 1;
    }
}


int E7(char *E7_tp, char *E7_p, char *E7_c) { // E7 -> E8 {E7'.h = E8.tp}E7' {E7.tp = E7'.s}
    char E8_tp[10], E8_p[10], E8_c[MAX_COD];
    char E7Linha_h[10], E7Linha_s[10], E7Linha_hp[10], E7Linha_sp[10], E7Linha_hc[MAX_COD], E7Linha_sc[MAX_COD];

    if (E8(E8_tp, E8_p, E8_c)) {
        strcpy(E7Linha_h, E8_tp);
        strcpy(E7Linha_hp, E8_p);
        strcpy(E7Linha_hc, E8_c);
        if (E7Linha(E7Linha_h, E7Linha_s, E7Linha_hp, E7Linha_sp, E7Linha_hc, E7Linha_sc)) {
            strcpy(E7_tp, E7Linha_s);
            strcpy(E7_p, E7Linha_sp);
            strcpy(E7_c, E7Linha_sc);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int E7Linha(char *E7Linha_h, char *E7Linha_s, char *E7Linha_hp, char *E7Linha_sp, char *E7Linha_hc, char *E7Linha_sc) { //E7' -> & E8{E7'2.h=tint;} E7'{E7'.s=E7'2.s} / e{E7'.s = E7'.h}
    char E8_tp[10], E8_p[10], E8_c[MAX_COD];
    char E7Linha2_h[10], E7Linha2_s[10], E7Linha2_hp[10], E7Linha2_sp[10], E7Linha2_hc[MAX_COD], E7Linha2_sc[MAX_COD];

    if (tk == TKELogico) {
        getToken();
        if (E8(E8_tp, E8_p, E8_c)) {
            strcpy(E7Linha2_h, "int");
            geratemp(E7Linha2_hp);
            sprintf(E7Linha2_hc, "%s%s\t%s = %s & %s\n", E7Linha_hc, E8_c, E7Linha2_hp, E7Linha_hp, E8_p);
            if (E7Linha(E7Linha2_h, E7Linha2_s, E7Linha2_hp, E7Linha2_sp, E7Linha2_hc, E7Linha2_sc)) {
                strcpy(E7Linha_s, E7Linha2_s);
                strcpy(E7Linha_sp, E7Linha2_sp);
                strcpy(E7Linha_sc, E7Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else {
        strcpy(E7Linha_s, E7Linha_h);
        strcpy(E7Linha_sp, E7Linha_hp);
        strcpy(E7Linha_sc, E7Linha_hc);
        return 1;
    }
}

int E8(char *E8_tp, char *E8_p, char *E8_c) { // E8 -> E9 {E8'.h = E9.tp}E8' {E8.tp = E8'.s}
    char E9_tp[10], E9_p[10], E9_c[MAX_COD];
    char E8Linha_h[10], E8Linha_s[10], E8Linha_hp[10], E8Linha_sp[10], E8Linha_hc[MAX_COD], E8Linha_sc[MAX_COD];

    if (E9(E9_tp, E9_p, E9_c)) {
        strcpy(E8Linha_h, E9_tp);
        strcpy(E8Linha_hp, E9_p);
        strcpy(E8Linha_hc, E9_c);
        if (E8Linha(E8Linha_h, E8Linha_s, E8Linha_hp, E8Linha_sp, E8Linha_hc, E8Linha_sc)) {
            strcpy(E8_tp, E8Linha_s);
            strcpy(E8_p, E8Linha_sp);
            strcpy(E8_c, E8Linha_sc);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int E8Linha(char *E8Linha_h, char *E8Linha_s, char *E8Linha_hp, char *E8Linha_sp, char *E8Linha_hc, char *E8Linha_sc) { // E8' -> == E9{E8'2.h=tint} E8' {E8'.s=E8'2.s}/ != E9 {E8'2.h=tint;}E8' {E8'.s=E8'2.s}/ e{E8'.s = E8'.h}
    char E9_tp[10], E9_p[10], E9_c[MAX_COD];
    char E8Linha2_h[10], E8Linha2_s[10], E8Linha2_hp[10], E8Linha2_sp[10], E8Linha2_hc[MAX_COD], E8Linha2_sc[MAX_COD];

    if (tk == TKComparadorIgual) {
        getToken();
        if (E9(E9_tp, E9_p, E9_c)) {
            strcpy(E8Linha2_h, "int");
            geratemp(E8Linha2_hp);
            sprintf(E8Linha2_hc, "%s%s\t%s = %s == %s\n", E8Linha_hc, E9_c, E8Linha2_hp, E8Linha_hp, E9_p);
            if (E8Linha(E8Linha2_h, E8Linha2_s, E8Linha2_hp, E8Linha2_sp, E8Linha2_hc, E8Linha2_sc)) {
                strcpy(E8Linha_s, E8Linha2_s);
                strcpy(E8Linha_sp, E8Linha2_sp);
                strcpy(E8Linha_sc, E8Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKComparadorDiferente) {
        getToken();
        if (E9(E9_tp, E9_p, E9_c)) {
            strcpy(E8Linha2_h, "int");
            geratemp(E8Linha2_hp);
            sprintf(E8Linha2_hc, "%s%s\t%s = %s != %s\n", E8Linha_hc, E9_c, E8Linha2_hp, E8Linha_hp, E9_p);
            if (E8Linha(E8Linha2_h, E8Linha2_s, E8Linha2_hp, E8Linha2_sp, E8Linha2_hc, E8Linha2_sc)) {
                strcpy(E8Linha_s, E8Linha2_s);
                strcpy(E8Linha_sp, E8Linha2_sp);
                strcpy(E8Linha_sc, E8Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else {
        strcpy(E8Linha_s, E8Linha_h);
        strcpy(E8Linha_sp, E8Linha_hp);
        strcpy(E8Linha_sc, E8Linha_hc);
        return 1;
    }
}

int E9(char *E9_tp, char *E9_p, char *E9_c) { // E9 -> E10 {E9'.h = E10.tp}E9' {E9.tp = E9'.s}
    char E10_tp[10], E10_p[10], E10_c[MAX_COD];
    char E9Linha_h[10], E9Linha_s[10], E9Linha_hp[10], E9Linha_sp[10], E9Linha_hc[MAX_COD], E9Linha_sc[MAX_COD];

    if (E10(E10_tp, E10_p, E10_c)) {
        strcpy(E9Linha_h, E10_tp);
        strcpy(E9Linha_hp, E10_p);
        strcpy(E9Linha_hc, E10_c);
        if (E9Linha(E9Linha_h, E9Linha_s, E9Linha_hp, E9Linha_sp, E9Linha_hc, E9Linha_sc)) {
            strcpy(E9_tp, E9Linha_s);
            strcpy(E9_p, E9Linha_sp);
            strcpy(E9_c, E9Linha_sc);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int E9Linha(char *E9Linha_h, char *E9Linha_s, char *E9Linha_hp, char *E9Linha_sp, char *E9Linha_hc, char *E9Linha_sc) { // E9' -> < E10{E9'2.h=tint}  E9'{E9'.s=E9'2.s}  / > E10{E9'2.h=tint} E9'{E9'.s=E9'2.s} / <= E10{E9'2.h=tint} E9'{E9'.s=E9'2.s} / >= E10{E9'2.h=tint} E9' {E9'.s=E9'2.s}/ e{E9'.s = E9'.h}
    char E10_tp[10], E10_p[10], E10_c[MAX_COD];
    char E9Linha2_h[10], E9Linha2_s[10], E9Linha2_hp[10], E9Linha2_sp[10], E9Linha2_hc[MAX_COD], E9Linha2_sc[MAX_COD];

    if (tk == TKMenor) {
        getToken();
        if (E10(E10_tp, E10_p, E10_c)) {
            strcpy(E9Linha2_h, "int");
            geratemp(E9Linha2_hp);
            sprintf(E9Linha2_hc, "%s%s\t%s = %s < %s\n", E9Linha_hc, E10_c, E9Linha2_hp, E9Linha_hp, E10_p);
            if (E9Linha(E9Linha2_h, E9Linha2_s, E9Linha2_hp, E9Linha2_sp, E9Linha2_hc, E9Linha2_sc)) {
                strcpy(E9Linha_s, E9Linha2_s);
                strcpy(E9Linha_sp, E9Linha2_sp);
                strcpy(E9Linha_sc, E9Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKMaior) {
        getToken();
        if (E10(E10_tp, E10_p, E10_c)) {
            strcpy(E9Linha2_h, "int");
            geratemp(E9Linha2_hp);
            sprintf(E9Linha2_hc, "%s%s\t%s = %s > %s\n", E9Linha_hc, E10_c, E9Linha2_hp, E9Linha_hp, E10_p);
            if (E9Linha(E9Linha2_h, E9Linha2_s, E9Linha2_hp, E9Linha2_sp, E9Linha2_hc, E9Linha2_sc)) {
                strcpy(E9Linha_s, E9Linha2_s);
                strcpy(E9Linha_sp, E9Linha2_sp);
                strcpy(E9Linha_sc, E9Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKComparadorMenorIgual) {
        getToken();
        if (E10(E10_tp, E10_p, E10_c)) {
            strcpy(E9Linha2_h, "int");
            geratemp(E9Linha2_hp);
            sprintf(E9Linha2_hc, "%s%s\t%s = %s <= %s\n", E9Linha_hc, E10_c, E9Linha2_hp, E9Linha_hp, E10_p);
            if (E9Linha(E9Linha2_h, E9Linha2_s, E9Linha2_hp, E9Linha2_sp, E9Linha2_hc, E9Linha2_sc)) {
                strcpy(E9Linha_s, E9Linha2_s);
                strcpy(E9Linha_sp, E9Linha2_sp);
                strcpy(E9Linha_sc, E9Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKComparadorMaiorIgual) {
        getToken();
        if (E10(E10_tp, E10_p, E10_c)) {
            strcpy(E9Linha2_h, "int");
            geratemp(E9Linha2_hp);
            sprintf(E9Linha2_hc, "%s%s\t%s = %s >= %s\n", E9Linha_hc, E10_c, E9Linha2_hp, E9Linha_hp, E10_p);
            if (E9Linha(E9Linha2_h, E9Linha2_s, E9Linha2_hp, E9Linha2_sp, E9Linha2_hc, E9Linha2_sc)) {
                strcpy(E9Linha_s, E9Linha2_s);
                strcpy(E9Linha_sp, E9Linha2_sp);
                strcpy(E9Linha_sc, E9Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else {
        strcpy(E9Linha_s, E9Linha_h);
        strcpy(E9Linha_sp, E9Linha_hp);
        strcpy(E9Linha_sc, E9Linha_hc);
        return 1;
    }
}

int E10(char *E10_tp, char *E10_p, char *E10_c) { // E10 -> E11 {E10'.h = E11.tp}E10' {E10.tp = E10'.s}
    char E11_tp[10], E11_p[10], E11_c[MAX_COD];
    char E10Linha_h[10], E10Linha_s[10], E10Linha_hp[10], E10Linha_sp[10], E10Linha_hc[MAX_COD], E10Linha_sc[MAX_COD];

    if (E11(E11_tp, E11_p, E11_c)) {
        strcpy(E10Linha_h, E11_tp);
        strcpy(E10Linha_hp, E11_p);
        strcpy(E10Linha_hc, E11_c);
        if (E10Linha(E10Linha_h, E10Linha_s, E10Linha_hp, E10Linha_sp, E10Linha_hc, E10Linha_sc)) {
            strcpy(E10_tp, E10Linha_s);
            strcpy(E10_p, E10Linha_sp);
            strcpy(E10_c, E10Linha_sc);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int E10Linha(char *E10Linha_h, char *E10Linha_s, char *E10Linha_hp, char *E10Linha_sp, char *E10Linha_hc, char *E10Linha_sc) { // E10' -> << E11{E10'2.h=tint}  E10'{E10'.s=E10'2.s} | >> E11{E10'2.h=tint}  E10'{E10'.s=E10'2.s} / e {E10'.s = E10'.h}
    char E11_tp[10], E11_p[10], E11_c[MAX_COD];
    char E10Linha2_h[10], E10Linha2_s[10], E10Linha2_hp[10], E10Linha2_sp[10], E10Linha2_hc[MAX_COD], E10Linha2_sc[MAX_COD];

    if (tk == TKShiftLeft) {
        getToken();
        if (E11(E11_tp, E11_p, E11_c)) {
            strcpy(E10Linha2_h, "int");
            geratemp(E10Linha2_hp);
            sprintf(E10Linha2_hc, "%s%s\t%s = %s << %s\n", E10Linha_hc, E11_c, E10Linha2_hp, E10Linha_hp, E11_p);
            if (E10Linha(E10Linha2_h, E10Linha2_s, E10Linha2_hp, E10Linha2_sp, E10Linha2_hc, E10Linha2_sc)) {
                strcpy(E10Linha_s, E10Linha2_s);
                strcpy(E10Linha_sp, E10Linha2_sp);
                strcpy(E10Linha_sc, E10Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKShiftRight) {
        getToken();
        if (E11(E11_tp, E11_p, E11_c)) {
            strcpy(E10Linha2_h, "int");
            geratemp(E10Linha2_hp);
            sprintf(E10Linha2_hc, "%s%s\t%s = %s >> %s\n", E10Linha_hc, E11_c, E10Linha2_hp, E10Linha_hp, E11_p);
            if (E10Linha(E10Linha2_h, E10Linha2_s, E10Linha2_hp, E10Linha2_sp, E10Linha2_hc, E10Linha2_sc)) {
                strcpy(E10Linha_s, E10Linha2_s);
                strcpy(E10Linha_sp, E10Linha2_sp);
                strcpy(E10Linha_sc, E10Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else {
        strcpy(E10Linha_s, E10Linha_h);
        strcpy(E10Linha_sp, E10Linha_hp);
        strcpy(E10Linha_sc, E10Linha_hc);
        return 1;
    }
}

int E11(char *E11_tp, char *E11_p, char *E11_c) { // E11 -> E12{E11'.h = E12.tp} E11' {E11.tp = E11'.s}
    char E12_tp[10], E12_p[10], E12_c[MAX_COD];
    char E11Linha_h[10], E11Linha_s[10], E11Linha_hp[10], E11Linha_sp[10], E11Linha_hc[MAX_COD], E11Linha_sc[MAX_COD];

    if (E12(E12_tp, E12_p, E12_c)) {
        strcpy(E11Linha_h, E12_tp);
        strcpy(E11Linha_hp, E12_p);
        strcpy(E11Linha_hc, E12_c);
        if (E11Linha(E11Linha_h, E11Linha_s, E11Linha_hp, E11Linha_sp, E11Linha_hc, E11Linha_sc)) {
            strcpy(E11_tp, E11Linha_s);
            strcpy(E11_p, E11Linha_sp);
            strcpy(E11_c, E11Linha_sc);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int E11Linha(char *E11Linha_h, char *E11Linha_s, char *E11Linha_hp, char *E11Linha_sp, char *E11Linha_hc, char *E11Linha_sc) { // E11' -> + E12{if(E11'.h==tint && E12.tp==tint) E11'2.h=tint; else E11'2.h=tfloat;} E11'2{E11'.s=E11'2.s} / - E12{if(E11'.h==tint && E12.tp==tint) E11'2.h=tint; else E11'2.h=tfloat;} E11'2{E11'.s=E11'2.s} / e {E11'.s = E11'.h}
    char E12_tp[10], E12_p[10], E12_c[MAX_COD];
    char E11Linha2_h[10], E11Linha2_s[10], E11Linha2_hp[10], E11Linha2_sp[10], E11Linha2_hc[MAX_COD], E11Linha2_sc[MAX_COD];

    if (tk == TKMais) {
        getToken();
        if (E12(E12_tp, E12_p, E12_c)) {
            if(!strcmp(E11Linha_h, "int") && !strcmp(E12_tp, "int"))
                strcpy(E11Linha2_h, "int");
            else
                strcpy(E11Linha2_h, "float");
            geratemp(E11Linha2_hp);
            sprintf(E11Linha2_hc, "%s%s\t%s = %s + %s\n", E11Linha_hc, E12_c, E11Linha2_hp, E11Linha_hp, E12_p);
            if (E11Linha(E11Linha2_h, E11Linha2_s, E11Linha2_hp, E11Linha2_sp, E11Linha2_hc, E11Linha2_sc)) {
                strcpy(E11Linha_s, E11Linha2_s);
                strcpy(E11Linha_sp, E11Linha2_sp);
                strcpy(E11Linha_sc, E11Linha2_sc);
                return 1;
            }
            else
                return 0;
        }
    } else if (tk == TKMenos) {
        getToken();
        if (E12(E12_tp, E12_p, E12_c)) {
            if(!strcmp(E11Linha_h, "int") && !strcmp(E12_tp, "int"))
                strcpy(E11Linha2_h, "int");
            else
                strcpy(E11Linha2_h, "float");
            geratemp(E11Linha2_hp);
            sprintf(E11Linha2_hc, "%s%s\t%s = %s - %s\n", E11Linha_hc, E12_c, E11Linha2_hp, E11Linha_hp, E12_p);
            if (E11Linha(E11Linha2_h, E11Linha2_s, E11Linha2_hp, E11Linha2_sp, E11Linha2_hc, E11Linha2_sc)) {
                strcpy(E11Linha_s, E11Linha2_s);
                strcpy(E11Linha_sp, E11Linha2_sp);
                strcpy(E11Linha_sc, E11Linha2_sc);
                return 1;
            }
            else
                return 0;
        }
    } else {
        strcpy(E11Linha_s, E11Linha_h);
        strcpy(E11Linha_sp, E11Linha_hp);
        strcpy(E11Linha_sc, E11Linha_hc);
        return 1;
    }
}

int E12(char *E12_tp, char *E12_p, char *E12_c) { // E12 -> E13 {E12'.h = E13.tp}E12' {E12.tp = E12'.s}
    char E13_tp[10], E13_p[10], E13_c[MAX_COD];
    char E12Linha_h[10], E12Linha_s[10], E12Linha_hp[10], E12Linha_sp[10], E12Linha_hc[MAX_COD], E12Linha_sc[MAX_COD];

    if (E13(E13_tp, E13_p, E13_c)) {
        strcpy(E12Linha_h, E13_tp);
        strcpy(E12Linha_hp, E13_p);
        strcpy(E12Linha_hc, E13_c);

        if (E12Linha(E12Linha_h, E12Linha_s, E12Linha_hp, E12Linha_sp, E12Linha_hc, E12Linha_sc)) {
            strcpy(E12_tp, E12Linha_s);
            strcpy(E12_p, E12Linha_sp);
            strcpy(E12_c, E12Linha_sc);
            return 1;
        }
        else
            return 0;
    } else
        return 0;
}

int E12Linha(char *E12Linha_h, char *E12Linha_s, char *E12Linha_hp, char *E12Linha_sp, char *E12Linha_hc, char *E12Linha_sc) {// E12' -> * E13{if(E12'.h==tint && E13.tp==tint) E12'2.h=tint; else E12'2.h=tfloat;} E12'{E12'.s=E12'2.s} / ÷ E13{if(E12'.h==tint && E13.tp==tint) E12'2.h=tint; else E12'2.h=tfloat;} E12'{E12'.s=E12'2.s} / % E13{if(E12'.h==tint && E13.tp==tint) E12'2.h=tint; else printf("Erro: operação de resto inválida"); exit(0);} E12'{E12'.s=E12'2.s} / e {E12'.s = E12'.h}
    char E13_tp[10], E13_p[10], E13_c[MAX_COD];
    char E12Linha2_h[10], E12Linha2_s[10], E12Linha2_hp[10], E12Linha2_sp[10], E12Linha2_hc[MAX_COD], E12Linha2_sc[MAX_COD];

    if (tk == TKMultiplicacao) {
        getToken();
        if (E13(E13_tp, E13_p, E13_c)) {

            if(!strcmp(E12Linha_h, "int") && strcmp(E13_tp, "int"))
                strcpy(E12Linha2_h, "int");
            else
                strcpy(E12Linha2_h, "float");
            geratemp(E12Linha2_hp);
            sprintf(E12Linha2_hc, "%s%s\t%s = %s * %s\n", E12Linha_hc, E13_c, E12Linha2_hp, E12Linha_hp, E13_p);
            if (E12Linha(E12Linha2_h, E12Linha2_s, E12Linha2_hp, E12Linha2_sp, E12Linha2_hc, E12Linha2_sc)) {
                strcpy(E12Linha_s, E12Linha2_s);
                strcpy(E12Linha_sp, E12Linha2_sp);
                strcpy(E12Linha_sc, E12Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKDivisao) {
        getToken();
        if (E13(E13_tp, E13_p, E13_c)) {
            if(!strcmp(E12Linha_h, "int") && strcmp(E13_tp, "int"))
                strcpy(E12Linha2_h, "int");
            else
                strcpy(E12Linha2_h, "float");
            geratemp(E12Linha2_hp);
            sprintf(E12Linha2_hc, "%s%s\t%s = %s / %s\n", E12Linha_hc, E13_c, E12Linha2_hp, E12Linha_hp, E13_p);
            if (E12Linha(E12Linha2_h, E12Linha2_s, E12Linha2_hp, E12Linha2_sp, E12Linha2_hc, E12Linha2_sc)) {
                strcpy(E12Linha_s, E12Linha2_s);
                strcpy(E12Linha_sp, E12Linha2_sp);
                strcpy(E12Linha_sc, E12Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKRestoDivisao) {
        getToken();
        if (E13(E13_tp, E13_p, E13_c)) {
            if(!strcmp(E12Linha_h, "int") && !strcmp(E13_tp, "int"))
                strcpy(E12Linha2_h, "int");
            else{
                printf("Erro: operação de resto inválida");
                exit(0);
            }
            geratemp(E12Linha2_hp);
            sprintf(E12Linha2_hc, "%s%s\t%s = %s %c %s\n", E12Linha_hc, E13_c, E12Linha2_hp, E12Linha_hp, 37, E13_p);
            if (E12Linha(E12Linha2_h, E12Linha2_s, E12Linha2_hp, E12Linha2_sp, E12Linha2_hc, E12Linha2_sc)) {
                strcpy(E12Linha_s, E12Linha2_s);
                strcpy(E12Linha_sp, E12Linha2_sp);
                strcpy(E12Linha_sc, E12Linha2_sc);
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else {
        strcpy(E12Linha_s, E12Linha_h);
        strcpy(E12Linha_sp, E12Linha_hp);
        strcpy(E12Linha_sc, E12Linha_hc);
        return 1;
    }
}

int E13(char *E13_tp, char *E13_p, char *E13_c) { // E13 -> E14 - {E13'.h = E14.tp}E13{E13.tp = E13'.s} / E14 ++{E13'.h = E14.tp} E13{E13.tp = E13'.s} / E14 -- {E13'.h = E14.tp}E13{E13.tp = E13'.s} / E14 !{E13'.h = E14.tp} E13{E13.tp = E13'.s} / E14 {E13.tp = E14.tp}
    char E14_tp[10], E14_p[10], E14_c[MAX_COD];
    char E13Linha_tp[10], E13Linha_h[10], E13Linha_s[10];

    if (E14(E14_tp, E14_p, E14_c)) {
        if (tk == TKMenos) {
            strcpy(E13Linha_h, E14_tp);
            getToken();
            if (E13(E13Linha_tp, E13Linha_h, E13Linha_s)) {
                strcpy(E13_tp, E13Linha_s);

                return 1;
            }
            else
                return 0;
        } else if (tk == TKMaisMais) {
            strcpy(E13Linha_h, E14_tp);
            getToken();
            if (E13(E13Linha_tp, E13Linha_h, E13Linha_s)) {
                strcpy(E13_tp, E13Linha_s);
                return 1;
            }
            else
                return 0;
        } else if (tk == TKMenosMenos) {
            strcpy(E13Linha_h, E14_tp);
            getToken();
            if (E13(E13Linha_tp, E13Linha_h, E13Linha_s)) {
                strcpy(E13_tp, E13Linha_s);
                return 1;
            }
            else
                return 0;
        } else if (tk == TKNegacao) {
            strcpy(E13Linha_h, E14_tp);
            getToken();
            if (E13(E13Linha_tp, E13Linha_h, E13Linha_s)) {
                strcpy(E13_tp, E13Linha_s);
                return 1;
            }
            else
                return 0;
        } else {
            strcpy(E13_tp, E14_tp);
            strcpy(E13_p, E14_p);
            strcpy(E13_c, E14_c);
            return 1;
        }
    }
    return 0;
}

int E14(char *E14_tp, char *E14_p, char *E14_c) { // E14 -> cte / id{E14.tp = consultaTipo(id, E14.tp, tabelaSimbolos)} RE / (E)
    char E_tp[10];

    if (tk == TKConstInt) {
        strcpy(E14_tp, "int");
        geratemp(E14_p);
        sprintf(E14_c,"\t%s = %s\n",E14_p,lex);
        getToken();
        return 1;
    } else if (tk == TKConstFloat) {
        strcpy(E14_tp, "float");
        geratemp(E14_p);
        sprintf(E14_c,"\t%s = %s\n",E14_p,lex);
        getToken();
        return 1;
    }else if (tk == TKId) {
        consultaTipo(lex, E14_tp, ts);
        if(strcmp(E14_tp, "int") && strcmp(E14_tp, "float")){
            printf("Variavel %s nao foi declarada\n", lex);
            exit(0);
        }
        strcpy(E14_p,lex);
        strcpy(E14_c,"");

        getToken();
        if (RE())
            return 1;
        else
            return 0;
    } else if (tk == TKAbrePar) {
        char E_p[MAX_COD],E_c[MAX_COD];
        getToken();
        if (E(E_tp, E_p, E_c)) {
            if (tk == TKFechaPar) {
                getToken();
                strcpy(E14_c,E_c);
                strcpy(E14_p,E_p);
                return 1;
            } else
                return 0;
        } else
            return 0;
    } else
        return 0;
}

int RE() { // RE -> (LP) / e
    if (tk == TKAbrePar) {
        getToken();
        if (LP()) {
            if (tk == TKFechaPar) {
                getToken();
                return 1;
            } else {
                printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else
            return 0;
    } else
        return 1;
}

int main() {
    char exp1[20000], lex[20], c;
    setbuf(stdout, NULL);
    FILE *entrada;
    ts = NULL;
    int i = 0;
    char PROGC_c[MAX_COD];

    // Informar arquivo de entrada
    if ((entrada = fopen("/home/felipe/Área de Trabalho/entrada", "r")) == NULL) {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }

    while (1) { // passa todo o conteudo do arquivo pra uma string
        c = fgetc(entrada);
        if (feof(entrada))
            break;
        if (c != 9 && c != 10 && c != 13) {
            exp1[i++] = c;
        } else if (c == 10) {
            exp1[i++] = 127;
        } else if (c == 9) {
            exp1[i++] = 9;
        }
    }
    exp1[i] = '\0';

    for (i = 0; i < 1000; i++) { // preenche matriz com -1 para melhor controle
        tksParser[i] = -1;
    }

    while ((tk = le_token(exp1, lex)) != -1) {

        coluna = posColuna - subColuna;
        char linhaSt[3];
        char colunaSt[3];
        snprintf(linhaSt, sizeof(linhaSt), "%d", linha);
        snprintf(colunaSt, sizeof(colunaSt), "%d", coluna);

        // Coloca no tksParser[] toda a estrutura dos tokens
        // A estrutura é a seguinte:
        // 0     1     2       3    4     5     ...
        // tk  linha coluna   tk  linha coluna  ...

        tksParser[posParser++] = tk;
        tksParser[posParser++] = linha;
        tksParser[posParser++] = coluna;
        strcpy(tksParserLex[posParserLex++], lex);
    }

    fclose(entrada);
    posParser = 0;
    posParserLex = 0;
    getToken(); // Avança na sentença

    if (PROGC(PROGC_c)) {
        printf("%s", PROGC_c);
        printf("Código de 3 enderecos gerado com sucesso.\nPressione ENTER para encerrar...");
        getchar();
    }
    else {
        printf("Falha no reconhecimento sintático\nPressione ENTER para encerrar...");
        getchar();
    }

}
