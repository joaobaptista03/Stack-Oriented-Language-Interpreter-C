/**
 * @file logical_operations.c
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com operações lógicas.
 * 
 */

#include "logical_operations.h"

#include <string.h>


/**
 *
 * Esta é a função que executa a operação ?, dada a stack e caso o token seja "?".
 * 
 * A operação ? dá pop aos 3 elementos do topo da stack e, se o último for verdade, dá push ao segundo, caso contrário 
 * dá push ao primeiro (topo).
 * 
 */
bool if_command (STACK *s, char *token) {
    if (strcmp(token, "?") == 0) {
        DATA top = pop(s);
        DATA top2 = pop(s);
        DATA top3 = pop(s);

        bool b = false;

        if (top3.type == 1) b = top3.elem.LONG;
        if (top3.type == 2) b = top3.elem.DOUBLE;

        if (b) push(s, top2);
        else push(s, top);

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação e>, dada a stack e caso o token seja "e>".
 * 
 * A operação e> dá pop aos 2 elementos do topo da stack e dá push do maior.
 * 
 */
bool higher2_command (STACK *s, char *token) {
    if (strcmp(token, "e>") == 0) {
        DATA top1 = pop(s);
        DATA top2 = pop(s);

        if (top1.type == 1 && top2.type == 1) {
            if (top1.elem.LONG > top2.elem.LONG) push(s,top1);
            else push(s, top2);
        }

        if (top1.type == 2 && top2.type == 2) {
            if (top1.elem.DOUBLE > top2.elem.DOUBLE) push(s,top1);
            else push(s, top2);
        }

        if (top1.type == 2 && top2.type == 1) {
            if (top1.elem.DOUBLE > top2.elem.LONG) push(s,top1);
            else push(s, top2);
        }

        if (top1.type == 1 && top2.type == 2) {
            if (top1.elem.LONG > top2.elem.DOUBLE) push(s,top1);
            else push(s, top2);
        }

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação e<, dada a stack e caso o token seja "e<".
 * 
 * A operação e< dá pop aos 2 elementos do topo da stack e dá push do menor.
 * 
 */
bool lower2_command (STACK *s, char *token) {
    if (strcmp(token, "e<") == 0) {
        DATA top1 = pop(s);
        DATA top2 = pop(s);

        if (top1.type == 1 && top2.type == 1) {
            if (top1.elem.LONG < top2.elem.LONG) push(s,top1);
            else push(s, top2);
        }

        if (top1.type == 2 && top2.type == 2) {
            if (top1.elem.DOUBLE < top2.elem.DOUBLE) push(s,top1);
            else push(s, top2);
        }

        if (top1.type == 2 && top2.type == 1) {
            if (top1.elem.DOUBLE < top2.elem.LONG) push(s,top1);
            else push(s, top2);
        }

        if (top1.type == 1 && top2.type == 2) {
            if (top1.elem.LONG < top2.elem.DOUBLE) push(s,top1);
            else push(s, top2);
        }

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação e|, dada a stack e caso o token seja "e|".
 * 
 * A operação e| dá pop aos 2 elementos do topo da stack e dá push ao que tiver valor verdadeiro, caso os dois sejam verdade, dá push ao segundo.
 * 
 */
bool or_command (STACK *s, char *token) {
    if (strcmp(token, "e|") == 0) {
        DATA top = pop(s);
        DATA top2 = pop(s);

        bool b1 = false;
        bool b2 = false;

        if (top.type == 1) b1 = top.elem.LONG;
        if (top.type == 2) b1 = top.elem.DOUBLE;

        if (top2.type == 1) b2 = top2.elem.LONG;
        if (top2.type == 2) b2 = top2.elem.DOUBLE;

        if (b2) push(s, top2);
        else if (b1) push(s, top);

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação e&, dada a stack e caso o token seja "e&".
 * 
 * A operação e& dá pop aos 2 elementos do topo da stack e dá push a "0" - Long Int caso um deles ou os dois não tenha valor verdadeiro,
 * ou dá push ao elemento do topo caso sejam os dois verdade.
 * 
 */
bool and_command (STACK *s, char *token) {
    if (strcmp(token, "e&") == 0) {
        DATA top = pop(s);
        DATA top2 = pop(s);

        bool b1 = false;
        bool b2 = false;

        if (top.type == 1) b1 = top.elem.LONG;
        if (top.type == 2) b1 = top.elem.DOUBLE;

        if (top2.type == 1) b2 = top2.elem.LONG;
        if (top2.type == 2) b2 = top2.elem.DOUBLE;

        if (b1 && b2) push(s, top);
        else push(s, create_data("0", 1));

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação >, dada a stack e caso o token seja ">".
 * 
 *  A operação > dá pop aos 2 elementos do topo da stack e dá push a "0" - Long Int caso o elemento do topo seja maior que o segundo,
 * caso contrário dá push a "1" - Long Int.
 * 
 */
bool higher_command (STACK *s, char *token) {
    if (strcmp(token, ">") == 0) {
        DATA top1 = pop(s);
        DATA top2 = pop(s);

        if (top1.type == 1 && top2.type == 1) {
            if (top1.elem.LONG < top2.elem.LONG) push(s, create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        if (top1.type == 2 && top2.type == 2) {
            if (top1.elem.DOUBLE < top2.elem.DOUBLE) push(s,create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        if (top1.type == 2 && top2.type == 1) {
            if (top1.elem.DOUBLE < top2.elem.LONG) push(s,create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        if (top1.type == 1 && top2.type == 2) {
            if (top1.elem.LONG < top2.elem.DOUBLE) push(s,create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação <, dada a stack e caso o token seja "<".
 * 
 *  A operação < dá pop aos 2 elementos do topo da stack e dá push a "1" - Long Int caso o elemento do topo seja maior que o segundo,
 * caso contrário dá push a "0" - Long Int.
 * 
 */
bool lower_command (STACK *s, char *token) {
    if (strcmp(token, "<") == 0) {
        DATA top1 = pop(s);
        DATA top2 = pop(s);

        if (top1.type == 3) {
            top1.type = 1;
            top1.elem.LONG = top1.elem.CHAR;
        }

        if (top2.type == 3) {
            top2.type = 1;
            top2.elem.LONG = top2.elem.CHAR;
        }

        if (top1.type == 1 && top2.type == 1) {
            if (top1.elem.LONG > top2.elem.LONG) push(s, create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        if (top1.type == 2 && top2.type == 2) {
            if (top1.elem.DOUBLE > top2.elem.DOUBLE) push(s,create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        if (top1.type == 2 && top2.type == 1) {
            if (top1.elem.DOUBLE > top2.elem.LONG) push(s,create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        if (top1.type == 1 && top2.type == 2) {
            if (top1.elem.LONG > top2.elem.DOUBLE) push(s,create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação =, dada a stack e caso o token seja "=".
 * 
 * A operação = dá pop aos 2 elementos do topo da stack e dá push a "1" - Long Int caso os dois elemntos forem iguais,
 * caso contrário dá push a "0" - Long Int.
 * 
 */
bool equal_command (STACK *s, char *token) {
    if (strcmp(token, "=") == 0) {
        DATA top1 = pop(s);
        DATA top2 = pop(s);

        if (top1.type == 1 && top2.type == 1) {
            if (top1.elem.LONG == top2.elem.LONG) push(s, create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        if (top1.type == 2 && top2.type == 2) {
            if (top1.elem.DOUBLE == top2.elem.DOUBLE) push(s,create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        if (top1.type == 2 && top2.type == 1) {
            if (top1.elem.DOUBLE == top2.elem.LONG) push(s,create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        if (top1.type == 1 && top2.type == 2) {
            if (top1.elem.LONG == top2.elem.DOUBLE) push(s,create_data("1", 1));
            else push(s, create_data("0", 1));
        }

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação !, dada a stack e caso o token seja "!".
 * 
 * A operação ! dá pop ao elemento do topo da stack e dá push a "1" - Long Int caso o elemento do topo seja falso,
 * caso contrário dá push a "1" - Long Int.
 * 
 */
bool no_command (STACK *s, char *token) {
    if (strcmp(token, "!") == 0) {
        DATA top = pop(s);

        bool b1 = false;

        if (top.type == 1) b1 = top.elem.LONG;
        if (top.type == 2) b1 = top.elem.DOUBLE;
        if (top.type == 3) b1 = top.elem.CHAR;

        if (b1) push(s, create_data("0", 1));
        else push(s, create_data("1", 1));

        return true;
    }
    return false;
}