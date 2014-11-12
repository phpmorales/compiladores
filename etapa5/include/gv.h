/*
 *
 * Author: Miller Biazus
 *		   Pedro Henrique Pinto Morales
 * UFRGS - Instituto de Informática
 * Etapa 4 - Compiladores - Prof. Marcelo de Oliveira Johann
 * 2014/2
 *
 */

/*
 *
 * gv.h
 * 
 * Funções públicas do módulo gv. Verifique a implementação para
 * maiores detalhes de como utilizar cada uma. 
 * 
 */

#ifndef __GV_H__
#define __GV_H__

/***************************************
 * Function: gv_init 
 * Description:
 * Input:
 * Output:
 ***************************************/
void gv_init (const char *filename);

/***************************************
 * Function: gv_close
 * Description:
 * Input:
 * Output:
 ***************************************/
void gv_close (void);

/***************************************
 * Function: gv_declare
 * Description:
 * Input:
 * Output:
 ***************************************/
void gv_declare (const int tipo, const void *pointer, char *name);

/***************************************
 * Function: gv_connect
 * Description:
 * Input:
 * Output:
 ***************************************/
void gv_connect (const void *p1, const void *p2);

#endif /* __GV_H__ */
