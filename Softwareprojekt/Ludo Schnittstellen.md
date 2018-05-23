# Ludo Schnittstellen für Frontend

## WICHTIGE HEADER

Access-Control-Allow-Credentials → true

Access-Control-Allow-Headers → Accept, X-Access-Token, X-Application-Name, X-Request-Sent-Time

Access-Control-Allow-Methods → GET, POST, OPTIONS

Access-Control-Allow-Origin → *

### Authenfikation

- Registration
- Login
- Logout
- Account löschen

### Lobby

- Lobby erstellen
- Lobby beitreten
- Lobby verlassen
- Lobby löschen
- Chatnachricht senden
- Chatnachrichten erhalten
- Spielerliste erhalten
- Spiel- / Lobbyinformationen erhalten
- Spiel starten
- Alexa Code senden

### Editor

- Karte erstellen/updaten/löschen/laden
- Kartenset erstellen/updaten/löschen/laden
- Aktionen erstellen/updaten/löschen/laden
- Spielfeld erstellen/updaten/löschen/laden
- Spielbrett erstellen/updaten/löschen/laden
- Würfel erstellen/updaten/löschen/laden
- Spielregeln erstellen/updaten/löschen/laden
- Generelle Spielinformationen erstellen/updaten/löschen/laden
- Spiel erstellen/updaten/löschen/laden

### Spiel

- Aktionsinfos zum Anzeigen erhalten
- Spielerpositionsinfos erhalten
- Karteninfos erhalten
- Gewürfelte Zahl erhalten
- Info, ob man selber an der Reihe ist
- Spielbrett laden (Kartenstapel, Spielfelder)

## Blabla Tim

##### Login

- POST
- /auth/login

Request-Body:

```json
{
    "username": NAME,
    "password": PASSWORD
}
```

Response-Body:

```json
{
    "username": NAME,
    "key": API-KEY
}
```

##### Registrierung

- PUT
- /auth/login

Request-Body:

```json
{
    "username": NAME,
    "password": PASSWORD
}
```

Response:																// hier direkter Login???

- 200 - wenn erfolgreiche Registrierung

##### Logout

- POST
- /auth/logout
  - apikey

Request-Body:

```json
{
    "username": NAME
}
```

Response:

- 200 - wenn Logout erfolgreich

##### Account löschen

- DELETE
- /auth/delete
  - apikey

Request-Body:

```json
{
    "username": NAME
}
```

Response:

- 200 - wenn Account gelöscht

##### Profil

- GET
- /profile
  - apikey

Response-Body:

```json
{
    "username": NAME,
    "email": EMAIL
}
```

##### Settings

- GET
- /settings
  - apikey

Response-Body:

```json
{
    "master": MASTERVOLUME,
    "music": MUSIKVOLUME,
    "sound": SOUNDVOLUME,
    "language": SPRACHE(Form: de_DE, en_US, etc.)
}
```

##### Spieleliste

- GET
- /gamelist
  - own - eigene oder Spiele von anderen
  - category - Spielekategorie
  - subcategory - Unterkategorie des Spiels
  - playerCount - Spieleranzahl

Respone-Body:

```json
[
    {
        "id": GAMEID,
        "name": GAMENAME
    },
    {
        "id": GAMEID,
        "name": GAMENAME
    }
]
```

##### Spieleinfo

- GET
- /gameinfo
  - id - Id des Spiels

Response-Body:

```json
{
    "id": id,
    "name": NAME,
    "icon": ICONID,
    "description": SPIELBESCHREIBUNG,
    "category": KATEGORIE,
    "subcategory": UNTERKATEGORIE,
    "minPlayers": MINIMALE SPIELERANZAHL,
    "maxPlayers": MAXIMALE SPIELERANZAHL
}
```

##### Spielerstellung

- PUT
- /lobby/create
  - apikey

Request-Body:

```json
{
    "id": GAMEID,
    "name": LOBBYNAME,
    "username": CREATORNAME,
    "password": PASSWORD,
    "playerCount": SPIELERANZAHL
}
```

Response-Body:

```json
{
    "id": LOBBYID
}
```

##### Lobby beitreten

- PUT
- /lobby/join
  - apikey

Request-Body:

```json
{
    "username": SPIELERNAME,
    "lobby": LOBBYID
}
```

Response:

- 200 - wenn Beitritt erfolgreich

##### Lobbyliste

- GET
- /lobby
  - apikey

Response-Body:

```json
[
    {
        "id": LOBBYID,
        "name": LOBBYNAME,
        "currentPlayers": SPIELERANZAHL,
        "maxPlayers": MAXIMALE SPIELERANZAHL,
        "password": TRUEFALSE
    }
]
```

##### Lobby verlassen

- POST
- /lobby/leave
  - apikey

Request-Body:

```json
{
    "username": USERNAME,
    "lobbyid": LOBBYID
}
```

Response:

- 200 - wenn Lobby erfolgreich verlassen

##### Lobby Spielerliste

- GET
- /lobby/players
  - apikey
  - lobbyid

Response-Body:

```json
[
    {
        "id": SPIELERID,
        "name": SPIELERNAME,
        "amazonecho": TRUEFALSE,
        "ping": PING											//Falls wir das haben wollen
    }
]
```

##### Lobby Kick Player

- DELETE
- /lobby/kick
  - apikey
  - lobbyid

Request-Body:

```json
{
    "id": SPIELERID
}
```

Response:

- 200 -  wenn Spieler erfolgreich gekickt
- 403 - wenn Sender kein Admin ist

##### Lobby Set New GameMaster

- POST
- /lobby/gamemaster
  - apikey
  - lobbyid

Request-Body:

```json
{
    "id": SPIELERID
}
```

Response:

- 200 -  wenn GameMaster erfolgreich gesetzt
- 403 - wenn Sender kein Admin ist

##### Lobby Spieler einladen

- PUT
- /lobby/invite
  - apikey
  - lobbyid

Request-Body:

```json
[
    {
        "username": SPIELERNAME
    }
]
```

Reponse:

200 - wenn alle Spieler erfolgreich eingeladen wurden

##### Lobby Auf Bereit setzen/starten

- POST
- /lobby/ready
  - apikey
  - lobbyid

Response-Body:

```json
{
    "ready": TRUEFALSE
}
```

##### Lobby Chat Nachricht senden

- POST
- /lobby/chat
  - apikey
  - lobbyid

Request-Body:

```
{
    "username": SPIELERNAME,
    "time": SENDEZEIT,
    "message": NACHRICHT
}
```

Response:

200 - wenn Nachricht vom Server empfangen

##### Lobby Chat Nachrichten abfragen

- GET
- /lobby/chat
  - apikey
  - lobbyid

Response-Body:

```json
//Es sollten nur noch nicht gesendete Chat Nachrichten gesendet werden
[
    {
        "username": SPIELERNAME,
        "time": ABSENDEZEIT,
        "message": NACHRICHT
    }
]
```

##### Lobby General Update

- GET
- /lobby
  - apikey
  - lobbyid

Response-Body:

```json
{
    "gamestart": TRUEFALSE			//Ist das Spiel gestartet
    "gamemaster": TRUEFALSE			//Wurde der Spieler zum GameMaster ernannt
    "kick": TRUEFALSE				//Wurde der Spieler gekickt
}
```

