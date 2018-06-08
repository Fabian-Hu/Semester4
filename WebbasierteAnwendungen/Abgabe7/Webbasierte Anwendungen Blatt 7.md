# Webbasierte Anwendungen Blatt 7

### Was muss der Browser machen, nachdem er folgende Antwort auf eine GET-Anfrage vom Server bekommen hat?

/HTTP/1.1 401 Unauthorized
Date: Mon, 13 Jan 2003 08:35:41 GMT
Server: Apache/1.3.24 (Win32) PHP/4.3.0
WWW-Authenticate: basic realm=“geschuetzterBereich“

Der Browser fragt nun nach dem Benutzernamen und dem dazugehörigen Passwort. 
Danach wird der GET-Request erneut gesendet, mit einem zusätzlichen Authorization-Header.
Das sieht dann ungefähr so aus:

GET /secure_document.html HTTP/1.0 
Accept: image/gif, image/jpeg, */* 
Accept-charset: iso-8859-1, *, utf-8 
Accept-encoding: gzip 
Accept-language: en 
User-Agent: Mozilla/4.51 [en] (WINNT; I) 
Authorization: Basic aGVpa286d29laHI 

Dabei muss man allerdings beachten, dass der Username und das Passwort zwar base64 codiert ist, aber dennoch unverschlüsselt gesendet wird.