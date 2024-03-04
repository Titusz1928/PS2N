# PS2N
Proiect sincretic, semestrul 2: sistem de conducere pe bază de microcontroller și tehnologii Cloud

Se va realiza un sistem de conducere pe bază de microcontroller și tehnologii Cloud (Azure for Students) care va efectua următoarele funcții:

Citirea temperaturii sistemului de la distanță.

Controlul luminilor LED de la distanță.

Transmiterea mesajelor prin internet către sistem.

Detecția și alertarea inundațiilor.

Interfața web

Sistemul va dispune de o interfață web ce va afișa temperatura curentă (citită de la un senzor LM35).

Va oferi posibilitatea de transmitere a unui mesaj către sistem (Cloud -> micro-controller).

Interfața va dispune de un buton de tip ON/OFF pentru controlul unui LED conecta la micro-controller.

Evenimentele de tip inundație vor fi transmise prin e-mail la o adresa prestabilită

Dezvoltarea Software

Se vor stoca în memoria nevolatilă ultimele 10 mesaje primite din Cloud.

Se vor stoca în memoria nevolatilă datele ultimelor 10 evenimente de tip inundație.

Pentru conectarea la internet a sistemului se poate folosi o comunicație serială cu un PC sau o conexiune Wi-Fi/Ethernet/3G.

Se pot folosi orice librării open-source.

Proiectul va avea un repository GitHub 

Teme opționale

Reglarea temperaturii de la distanță. Regulator format din senzorul de temperatură și sursă de căldură controlată prin PWM.

Stabilirea unui orar zilnic de funcționare din interfața web pentru luminile LED.

 

Etape de dezvoltare:

Se va afișa pe interfața serială (SerialMonitor) temperatura curentă citită de la un senzor de temperatura (LM35) și se va implementa controlul unui LED prin comenzi UART (ie: ‘A’ -> va aprinde LED-ul, ‘S’ -> va stinge LED-ul). (Termen limită: 11.03.2024)

Implementarea unei interfețe WEB folosind Flask (Python) prin care se vor putea vizualiza starea curentă a LED-ului și temperatura curentă. Interfața va permite de asemenea și controlul LED-ului de la distanță. (Termen limită: 25.03.2024)

Trimiterea mesajelor din interfața WEB către microcontroller. Ultimele 10 mesaje vor fi stocate în memoria EEPROM. (Termen limită: 08.04.2024)

Detectarea inundațiilor și trimiterea unei notificări prin e-mail. Ultimele 10 evenimente vor fi stocate în EEPROM. Interfața WEB va permite ștergerea individuală a fiecărui eveniment. (Termen limită: 22.04.2024) 

Implementarea interfeței WEB dezvoltată anterior în Cloud folosind Azure for Students. (Termen limită: 21.05.2024)

Prezentare finală: 26.05.2024.

 

Exemplu listă componente:

Arduino Uno/Nano

Senzor de temperatură LM35/DHT11/DHT22

Buton/Senzor inundație

LED + rezistor
