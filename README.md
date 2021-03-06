# Arduino-Sensor-de-temperatura-con-sistema-de-enfriamento-ajustable

## Función:
Sensor de temperatura automático con sistema de enfriamiento (ventilador) ajustable manualmente mediante el uso botones, uno para ajustar en tiempo real el limite inferior de temperatura y otro para el limite superior de temperatura, con el cual el ventilador se activa al llegar a la temperatura limite máxima. 

## Material necesario:
* Arduino uno
* Sensor de temperatura Dallas 18b20
* Resistencia de 4.7 kΩ
* Ventilador (5V-12V)
* Integrado ULN2003APG
* 2 pulsadores

### Objetivo del proyecto:
Desarrollar un sensor de temperatura que cuando, gracias al integrado ULN2003APG, detecte una temperatura mayor a 27 grados centigrados, activando automaticamente el ventilador.

#### Diagrama del circuito:
![](Img/Imagen%201%20diagrama.png)

#### Montaje:
![](Img/Imagen%202%20foto.jpeg)

![](Img/Imagen%203%20Foto.png)

# Resultados:
Cuando el sensor Dallas 18b20 detecta una temperatura de 27 C, mediante el integrado ULN2003APG se activa el ventilador, mientras no se detecte el ventilador parmanece inactivo. El operador puede modificar estas temperaturas manualmente mediante eluso de los pulsadores, siendo uno para disminuir la temperatura limite de activacion y el otro para aumentarla.
