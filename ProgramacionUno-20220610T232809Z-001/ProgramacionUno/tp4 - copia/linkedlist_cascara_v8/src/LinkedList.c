#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size =0;
        this-> pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNodo = NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex < ll_len(this))
    {
        pNodo = this->pFirstNode;
        for(int i=nodeIndex; i>0;  i--)
        {
            pNodo = pNodo->pNextNode;
        }
    }

    return pNodo;
}
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
        /*
    if(this!=NULL)
    {


    }
    */

    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo = NULL;
    Node* nodoAnterior = NULL;


    if(this!=NULL && nodeIndex>=0 && nodeIndex <=ll_len(this))
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));
        if(nuevoNodo!=NULL)
        {
            nuevoNodo->pElement = pElement;
            nuevoNodo->pNextNode = getNode(this, nodeIndex);

            if(nodeIndex==0)
            {
                this->pFirstNode = nuevoNodo;
            }
            else
            {
                nodoAnterior = getNode (this, nodeIndex-1);
                nodoAnterior->pNextNode = nuevoNodo;
            }
            this->size++;
            returnAux=0;

        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
        return addNode(this, ll_len(this), pElement);
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada // permite obtener un elemento de la lista en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo = NULL;

    if(this!=NULL && index>=0 && index < ll_len(this))
    {
        pNodo=getNode(this, index);
        if(pNodo!=NULL)
        {
            returnAux=pNodo->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodo = NULL;

    if(this!=NULL && index>=0 && index < ll_len(this))
    {
        pNodo=getNode(this, index);
        if(pNodo!=NULL)
        {
            pNodo->pElement = pElement;

            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
	Node* nodoAnterior=getNode(this,index-1);
    Node* nodoActual=getNode(this,index);
	Node* nodoSiguiente=getNode(this,index+1);


    if(this!=NULL && index>=0 && index<=ll_len(this) && nodoActual!=NULL)
    {
    	if(index==0)
    	{
            this->pFirstNode=nodoSiguiente;
    		free(nodoActual);
    		this->size--;
    		returnAux=0;
    	}
    	else
    	{
    	    //si eliminio el nodo 5 el nodo anterior es el 4 y el siguiente es el 6 entonces el nodo anterior (indice 4)tiene que apuntar al 6 que pasaria al ser el nuevo 5
    		nodoAnterior->pNextNode=nodoSiguiente;
    		free(nodoActual);
    		this->size--;
    		returnAux=0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;


    if(this!=NULL)
    {
        for(int i=0; i<ll_len(this);  i++)
        {
            ll_remove(this, i);
        }

        returnAux=0;
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;

    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNodo=NULL;

    if(this!=NULL)
    {
        for(int i=0; i<ll_len(this);  i++)
        {
           pNodo=getNode(this, i);
           if(pNodo!=NULL)
           {
               if(pNodo->pElement == pElement)
               {
                   returnAux=i;
                   break;
               }
           }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_len(this )==0)
       {
           returnAux=1;

       }
       else
       {

           returnAux=0;
       }

    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if (this!=NULL && index<=ll_len(this) && index>=0)
    {
        Node* nodoActual=NULL;

    	for(int i=index ;i<ll_len(this); i++)
        {
    		nodoActual=getNode(this,i);
    		nodoActual->pNextNode=nodoActual;

    	}
    	addNode(this, index, pElement);
		returnAux=0;
    }

    return returnAux;
}



/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* nodoActual=NULL;

    if(this!=NULL && index<=ll_len(this) && index>=0)
    {
        nodoActual=getNode(this,index);

        if(nodoActual!=NULL)
        {
           returnAux =  nodoActual->pElement;
           free(nodoActual);

        }
        this->size--;
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodoActual=NULL;
    int estaElElemento=0;

    if (this!=NULL)
    {
    	for(int i=0 ;i<ll_len(this); i++)
        {
    		nodoActual=getNode(this,i);
    		if(nodoActual!=NULL)
            {
                if(nodoActual->pElement==pElement)
                {
                    estaElElemento=1;

                }
            }
    	}

    	if(estaElElemento)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{

    int returnAux = -1;
    Node* nodoActualThisDos=NULL;
    int estaElElemento=0;

    if (this!=NULL && this2!=NULL)
    {
        if(ll_len(this2)<=ll_len(this))
        {
            for(int i=0 ;i<ll_len(this2); i++)
            {
                nodoActualThisDos=getNode(this,i);

                if(nodoActualThisDos!=NULL)
                {
                    if(ll_contains(this, nodoActualThisDos->pElement))
                    {
                        estaElElemento=1;

                    }
                    else
                    {
                        estaElElemento=0;
                    }
                }
            }
        }

    	if(estaElElemento)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }


    return returnAux;
}


/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len=ll_len(this);
    void* cosaAClonar;

    if (this!=NULL && from>=0 && to>=0 && to>from && to<=len)
    {
    	cloneArray=ll_newLinkedList();

    	for(int i=from;i<to;i++)
        {
    		cosaAClonar=ll_get(this,i);
    		ll_add(cloneArray, cosaAClonar);
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int tam=ll_len(this);


    if(this!=NULL && tam>=0)
    {

        cloneArray=ll_subList(this, 0, tam);


    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio 1 si es mayor// -1 si es menor
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* cosaUno;
    void* cosaDos;
    int len=ll_len(this);

	if (this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
		for (int i=0; i<len-1; i++)
        {

			for (int j=i+1; j<len; j++)
            {
                cosaUno=ll_get(this,i);
				cosaDos=ll_get(this,j);

				//si el orden es 1 es xq es ascendernte (el menor primero) y si la funcion retorna 1 es xq el primer elemnto es mayor al segundo
				// por lo que se debe ordenar, es decir lo que esta en la cosa uno debe ir en la cosa dos
				if (pFunc(cosaUno,cosaDos)==1 && order==1)
                {
					ll_set(this,i,cosaDos); //lo que esta en el coso dos va al nodo uno
					ll_set(this,j,cosaUno);
				}
				else
                {
                    if (pFunc(cosaUno,cosaDos)==-1 && order==0)
                    {
                        ll_set(this,i,cosaDos);
                        ll_set(this,j,cosaUno);
                    }

				}
			}
		}
		 returnAux=0;
	}
    return returnAux;

}

