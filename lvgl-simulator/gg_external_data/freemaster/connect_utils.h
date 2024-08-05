/*
 * SPDX-License-Identifier: MIT
 * Copyright 2023 NXP
 */

#ifndef CONNECT_UTILS_H
#define CONNECT_UTILS_H

#include <curl/curl.h>

/*
   * @param   {char*} ws_url: websocket link eg: ws://127.0.0.1:41000.
   * @returns {CURL* } the pointer of the curl connection.
*/
CURL * websocket_connect(const char *ws_url);

/*
   * @param   {CURL *} ws_curl: the pointer of the curl connection.
   * @param   {char *} parm: the request data with json string.
   * @returns {char *} the websocket response data with json string.
*/
char *websocket_request(CURL *ws_curl, char *parm);

/*
   * for close the websocket connection.
   * @param  {CURL *} ws_curl: the pointer of the curl connection.
*/
void websocket_close(CURL *ws_curl);

/*
   * for http request function.
   * @param   {const char *} url: http link eg: http://127.0.0.1:41000.
   * @param   {const char *} parm: http post request parameters.
*/
char *http_request(const char *url, const char *parm);

#endif