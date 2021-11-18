# noFire - Simple fire detector by Arduino #

This branch is a development branch. If you want the stable branch, check the stale branch.

## Current status ##
	✔ Temperature check
	✔ Humidity check
	✔ Temperature + Humidity at the same time (to analyze if a fire is taking place)
	✔ Buzzer support [UNTESTED]
	✔ MQ2 Gas sensor support [UNTESTED]
	✔ Final Product

## PIN Setups ##
- Pin 5: MQ2 Smoke sensor
- Pin 8: Buzzer
- Pin 11: DH11 Heat sensor

## Notes ##
Import The ZIP into Arduino libraries as `dht.h` relies on it.

`smokeThres` can (and should) be finetuned as we are not 100% keen on the sensor's sensitivity yet.