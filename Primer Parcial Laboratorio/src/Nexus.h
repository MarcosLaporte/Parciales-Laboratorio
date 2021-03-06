/*
 * Nexus.h
 *      Author: Marcos
 */

#ifndef NEXUS_H_
#define NEXUS_H_

#include "Input.h"
#include "Clients.h"
#include "Request.h"
#include "Locality.h"

//---------------------------------------------------------------------------------
/// @brief Crea un pedido de recolecci?n en el primer lugar vac?o del array, pidiendo el ID
/// 	del cliente al que se le quiere asiganer el pedido, y si luego de 3 intentos el usuario
/// 	ingresa mal el ID, se cancela. Si acepta el ID, lo a asigna 'clientId'. El ID del pedido
/// 	lo toma del par?metro. Pide el total de kilos, cambia el estado e 'isEmpty' a 1.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama?o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama?o del array de pedidos.
/// @param requestId - Valor del ID a asignar al pedido.
/// @return int - Retorna -1 si no existe el ID ingresado, 0 si no encuentra espacio, o 1 si est? todo bien.
int addRequest(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int requestId, sLocality* localList, int localLen);
//---------------------------------------------------------------------------------
/// @brief Imprime la lista de pedidos pendientes con encabezado, llamando a la funci?n printPendingRequests()
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama?o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama?o del array de pedidos.
/// @return int - Retorna -1 si alg?n puntero es nulo o alg?n tama?o es inv?lido, o 0 si est? todo bien.
int printPendingRequestList(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
//---------------------------------------------------------------------------------
/// @brief Imprime un pedido pendiente, validando que los IDs de ambas estructuras concuerden.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama?o del array de clientes.
/// @param request - Pedido a imprimir.
/// @return int - Retorna -1 si el puntero es nulo o el tama?o es inv?lido, o 0 si est? todo bien.
int printPendingRequest(sClient* clientsList, int cliLen, sRequest request);
//---------------------------------------------------------------------------------
/// @brief Cambia el estado del pedido indicado a 1 (COMPLETED). Pide el ID del pedido, y si luego de 3
/// 	intentos no ingresa uno v?lido, la acci?n se cancela. Pide la cantidad de los 3 tipos de pl?stico
/// 	y los asigna a sus respectivos campos en la posici?n del array indicada.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama?o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama?o del array de pedidos.
/// @return int - Retorna -1 si no existe ese ID, o 0 si est? todo bien.
int loadRequest(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
//---------------------------------------------------------------------------------
/// @brief Se encarga de sumar la cantidad de pedidos pendientes de cada cliente. Esta funci?n se llama
/// 	junto a initPendingRequests() cada vez que se ingresa o se procesa un pedido.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama?o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama?o del array de pedidos.
/// @param clientId - El ID del cliente a contar sus pedidos pendientes.
/// @return int - Retorna -1 si el pedido no est? cargado, pendiente y el ID de su cliente
/// 	no concuerda con el mismo pasado por par?metro.
int countRequestsByClient(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int clientId);
//---------------------------------------------------------------------------------
/// @brief Se encarga de sumar la cantidad de pedidos procesados de cada cliente. Esta funci?n se llama
/// 	junto a initCompletedRequests() cada vez que se ingresa o se procesa un pedido.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama?o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama?o del array de pedidos.
/// @param clientId - El ID del cliente a contar sus pedidos pendientes.
/// @return int - Retorna -1 si el pedido no est? cargado, pendiente y el ID de su cliente
/// 	no concuerda con el mismo pasado por par?metro.
int countCompletedRequestsByClient(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int clientId);
//---------------------------------------------------------------------------------
/// @brief Imprime la lista de pedidos procesados con encabezado, llamando a la funci?n printCompletedRequestByClientId().
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama?o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama?o del array de pedidos.
/// @return int - Retorna -1 si alg?n puntero es nulo o alg?n tama?o es inv?lido, o 0 si est? todo bien.
int printCompletedRequests(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
//---------------------------------------------------------------------------------
/// @brief Imprime la lista de pedidos procesados, validando que los IDs de ambas estructuras concuerden.
///
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama?o del array de pedidos.
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama?o del array de clientes.
/// @param clientId - El Id del cliente a comparar con el de la lista de pedidos.
/// @return int - Retorna -1 si el pedido no est? cargado, procesado y el ID de su cliente
/// 	no concuerda con el mismo pasado por par?metro.
int printCompletedRequestByClientId(sRequest* requestList, int reqLen, sClient* clientsList, int cliLen, int clientId);
//---------------------------------------------------------------------------------
/// @brief Acumula los kilos de polipropileno y cuenta la cantidad de clientes asociados con estos.
/// 	Luego divide ambos para tener un promedio de polipropileno por cliente
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama?o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama?o del array de pedidos.
/// @param average - Puntero a guardar el promedio.
/// @return int - Retorna -1 si no encontr? ning?n cliente con un pedido procesado, o 0 si s?.
int countAveragePP(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, float* average);
//---------------------------------------------------------------------------------
/// @brief Imprime por pantalla los datos del cliente pasados por par?metro.
///
/// @param client - El cliente a imprimir.
/// @return int - Retorna -1 si el cliente pasado por par?metro tiene su 'status' en 0 (VACIO), o 0 si est? en 1.
int printClient(sClient client, sLocality* localList, int localLen);
//---------------------------------------------------------------------------------
/// @brief Imprime por pantalla los datos del cliente pasados por par?metro con la cantidad de pedidos procesados.
///
/// @param client - El cliente a imprimir.
/// @return int - Retorna -1 si el cliente pasado por par?metro tiene su 'status' en 0 (VACIO), o 0 si est? en 1 (FULL).
int printClientCompletedRequest(sClient client, sLocality* localList, int localLen);
//---------------------------------------------------------------------------------
/// @brief Imprime toda la lista de empleados con un encabezado, llamando a la funci?n printClient().
///
/// @param list - Puntero al array de clientes.
/// @param len - Indica el tama?o del array.
/// @return int - Retorna -1 si el puntero es nulo o el tama?o es inv?lido, o 0 si est? todo bien.
int printClientList(sClient* list, int len, sLocality* localList, int localLen);
//---------------------------------------------------------------------------------
/// @brief Imprime por pantalla la lista de clientes, pide una localidad e imprime su cantidad de pedidos pendientes
///
/// @param list - Puntero al array de clientes.
/// @param len - Indica el tama?o del array.
/// @return int - Retorna -1 si el puntero es nulo o el tama?o es inv?lido, o 0 si est? todo bien.
int printLocalityRequests(sClient* list, int cliLen, sLocality* localList, int localLen);
//---------------------------------------------------------------------------------
/// @brief Cuenta la cantidad de pedidos pendientes de la localidad pasada por par?metro.
///
/// @param list - Puntero al array de clientes.
/// @param len - Indica el tama?o del array.
/// @param locality - La localidad a buscar.
/// @param accum - Puntero a donde se va a guardar la cantidad de pedidos pendientes.
/// @return int - Retorna -1 si no encuentra la localidad, o 0 si est? todo bien.
int calculateLocalityRequests(sClient* list, int len, int localityId, int* accum);
//---------------------------------------------------------------------------------
int printClientsMaxRequests(sClient* cliList, int cliLen, sLocality* localList, int localLen, int reqStatus, int max);
/// @brief Datos hardcodeados para probar el c?digo.
///
/// @param clientsList - Puntero al array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param maxClients - Cantidad de clientes a hardcodear.
/// @param ids - Puntero a los IDs.
/// @param maxRequests - Cantidad de pedidos a hardcodear.
/// @param reqIds - Puntero a los IDs de pedidos.
void hardcodeClients(sClient* clientsList, sRequest* requestList, int maxClients, int* ids, int maxRequests, int* reqIds);
//---------------------------------------------------------------------------------

#endif /* NEXUS_H_ */
