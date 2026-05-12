## 7. Analiza sustava

### 7.1 Potrošnja energije (teorijska analiza)

Sustav koristi dva režima rada:
- aktivni rad (mjerenje i obrada podataka)
- Light Sleep (neaktivno stanje)

Prosječna potrošnja može se aproksimirati formulom:

I_avg = (I_active × t_active + I_sleep × t_sleep) / T_total

gdje su:
- I_active ≈ 80–120 mA (ESP32 aktivno)
- I_sleep ≈ 0.8–1.5 mA (Light Sleep)
- t_active ≈ 1–2 s
- t_sleep ≈ 10 s

---

### 7.2 Utjecaj duty cycle-a

Sustav ima vrlo nizak duty cycle:

- aktivno stanje: ~10–15%
- sleep stanje: ~85–90%

Zaključak:
➡ većina vremena sustav provodi u niskopotrošnom stanju

---

### 7.3 Utjecaj Light Sleep režima

Prednosti:
- brzo buđenje (~ms razina)
- očuvanje RAM-a i RTC memorije
- minimalna kompleksnost implementacije

Nedostaci:
- veća potrošnja od Deep Sleep-a
- RAM ostaje napajan

---

### 7.4 Ograničenja simulacije (Wokwi)

Wokwi simulator:
- ne simulira stvarnu struju potrošnje
- ne prikazuje razlike između sleep modova u energiji
- koristi se isključivo za logičku verifikaciju sustava

---

### 7.5 Procjena trajanja baterije

Za bateriju od 2500 mAh:

- prosječna potrošnja ≈ 15–30 mA (procjena)
- trajanje ≈ 3–7 dana (ovisno o opterećenju)

U stvarnom uređaju Deep Sleep bi značajno produžio trajanje (na mjesece).

---

### 7.6 Zaključak analize

Implementirani sustav uspješno demonstrira koncept upravljanja energijom kroz:
- periodičko buđenje
- smanjenje aktivnog vremena
- korištenje Light Sleep režima

Iako Wokwi ne omogućuje precizno mjerenje potrošnje, logika sustava odgovara realnim IoT implementacijama.