# Dijagram stanja sustava

## State machine

@startuml

[*] --> ACTIVE

state ACTIVE {
  ACTIVE : mjerenje temperature
  ACTIVE : mjerenje vlage
  ACTIVE : spremanje podataka
}

state SLEEP {
  SLEEP : Light Sleep (10s)
  SLEEP : timer wake-up
}

state WAKE {
  WAKE : nastavak rada
  WAKE : RTC memorija aktivna
}

ACTIVE --> SLEEP : kraj ciklusa
SLEEP --> WAKE : timer interrupt
WAKE --> ACTIVE : ponavljanje

@enduml