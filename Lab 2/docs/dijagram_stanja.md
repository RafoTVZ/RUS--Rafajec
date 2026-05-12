# Dijagram stanja sustava

## State machine

@startuml

state ACTIVE {
  :mjerenje temperature;
  :mjerenje vlage;
  :spremanje podataka;
}

state SLEEP {
  :Light Sleep (10s);
  :timer wake-up;
}

state WAKE {
  :nastavak rada;
  :RTC memorija aktivna;
}

ACTIVE --> SLEEP : kraj ciklusa
SLEEP --> WAKE : timer interrupt
WAKE --> ACTIVE : ponavljanje

@enduml