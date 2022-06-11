#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED

/** \brief Parsea los datos de los paises desde el archivo txt (modo texto).
 *
 * \param pFile FILE* ubicacion del archivo
 * \param pArrayListaPaises LinkedList* lista de paises
 * \return int retorna 0 si hubo algun error o 1 en caso de no haber error.
 *
 */
int parser_PaisText(FILE* pFile, LinkedList* pArrayListaPaises);

//int parser_PaisBin(FILE* pFile , LinkedList* pArrayListaPaises);
