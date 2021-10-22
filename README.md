# Arduino Öntözőrendszer
## Bemutatkozás
Ebben a projektben egy Arduino alapú automata öntözőrendszer kerül bemutatásra. Ez a rendszer egy Arduino Uno segítségével egy kapacitív talajnedvesség érzékelő által méri a termőföld nedvességszázalékát és alapján működtet egy szivattyút, amely 3 másodpercig öntöz, ha a föld nedvességszázaléka egy adott érték alá esik. Továbbá integrálásra került egy ultrahangos távolságérzékelő, amely arra szolgál, hogy méri a tartályban található vízmennyiséget, így a pumpa sosem fog szárazan menni és egy hőmérséklet és párataralom mérő.

Ezen adatok egy WiFi modul segítégével, egy weboldal adatbázisában lesznek tárolva, melyet a világ bármelyik pontjáról, az ott található gráf segítségével leolvashatunk.

![kep](https://i.imgur.com/Q4KNv9Y.jpg)



## Szükséges alkatrészek
- [Arduino Uno](https://www.hestore.hu/prod_10033329.html)
- [Kapacitív talajnedvesség érzékelő](https://www.hestore.hu/prod_10040575.html)
- [5V-os merülő szivattyú](https://www.hestore.hu/prod_10042009.html?he)
- [Ultrahangos távolságérzékelő](https://www.hestore.hu/prod_10035534.html?lang=hu)
- [5V-os relé](https://www.hestore.hu/prod_10035812.html)
- [Próbapanel](https://www.hestore.hu/prod_10035535.html)
- [Jumper wire (male-male)](https://www.hestore.hu/prod_10036629.html?lang=hu)
- [Jumper wire (female-female)](https://www.hestore.hu/prod_10035719.html)
- [Szilikon cső 6 x 9mm](https://www.hestore.hu/prod_10041946.html)
- [NodeMCU ESP8266 WiFi modul](https://www.hestore.hu/prod_10036631.html)
- [DHT11 Hőmérséklet és párataralom mérő](https://www.hestore.hu/prod_10035544.html)

## Wiki
[1. Megismerkedés az Arduinoval](https://github.com/tothdomi22/Arduino-Plant_Watering_Station/wiki/1.-Megismerked%C3%A9s-az-Arduinoval)

[2. Szükséges alkatrészek](https://github.com/tothdomi22/Arduino-Plant_Watering_Station/wiki/2.-Sz%C3%BCks%C3%A9ges-alkatr%C3%A9szek)

[3. Nevességérzékelő hozzákötése az Arduinohoz](https://github.com/tothdomi22/Arduino-Plant_Watering_Station/wiki/3.-Nevess%C3%A9g%C3%A9rz%C3%A9kel%C5%91-hozz%C3%A1k%C3%B6t%C3%A9se-az-Arduinohoz)

[4. Relé és szivattyú hozzákőtése az Arduinohoz](https://github.com/tothdomi22/Arduino-Plant_Watering_Station/wiki/4.-Rel%C3%A9-%C3%A9s-szivatty%C3%BA-hozz%C3%A1k%C5%91t%C3%A9se-az-Arduinohoz)

[5. Nedvességérzékelő és Szivattyű együttes működése](https://github.com/tothdomi22/Arduino-Plant_Watering_Station/wiki/5.-Nedvess%C3%A9g%C3%A9rz%C3%A9kel%C5%91-%C3%A9s-Szivatty%C5%B1-egy%C3%BCttes-m%C5%B1k%C3%B6d%C3%A9se)

[6. Távolságérzékelő és DHT11 rendszerbe integrálása](https://github.com/tothdomi22/Arduino-Plant_Watering_Station/wiki/6.T%C3%A1vols%C3%A1g%C3%A9rz%C3%A9kel%C5%91-%C3%A9s-DHT11-rendszerbe-integr%C3%A1l%C3%A1sa)

[7. Arduino által mért adatok tárolása Weboldalon](https://github.com/tothdomi22/Arduino-Plant_Watering_Station/wiki/7.-Arduino-%C3%A1ltal-m%C3%A9rt-adatok-t%C3%A1rol%C3%A1sa-Weboldalon)

[8. Adatok vizuális megjelenítése](https://github.com/tothdomi22/Arduino-Plant_Watering_Station/wiki/8.-Adatok-vizu%C3%A1lis-megjelen%C3%ADt%C3%A9se)

[9. Push notification](https://github.com/tothdomi22/Arduino-Plant_Watering_Station/wiki/9.-Push-notification)
