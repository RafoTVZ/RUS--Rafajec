# Izvještaj – Lab2 ESP32 Datalogger

## 1. Cilj
Cilj vježbe je implementirati sustav za upravljanje potrošnjom energije korištenjem ESP32 mikrokontrolera i Light Sleep režima.

---

## 2. Opis sustava
Sustav periodički mjeri temperaturu i vlagu te sprema podatke u RTC memoriju. Nakon svakog ciklusa ulazi u Light Sleep na 10 sekundi.

---

## 3. Implementacija

Korištene funkcionalnosti:
- RTC_DATA_ATTR za spremanje podataka
- esp_light_sleep_start()
- timer wake-up (10s)
- simulacija senzora

---

## 4. Upravljanje energijom
ESP32 ulazi u Light Sleep nakon svakog mjerenja i budi se timerom.

---

## 5. Ograničenja Wokwi simulatora
Wokwi ne simulira stvarnu potrošnju energije niti potpuno realistično ponašanje sleep modova.

---

## 6. Zaključak
Implementiran je funkcionalan model periodičkog buđenja i upravljanja energijom, ali bez realne analize potrošnje zbog ograničenja simulatora.