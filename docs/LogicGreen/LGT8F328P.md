# Guía rápida LogicGreen LGT8F328P
Esta implementación de Aixt para LogicGreen da soporte a la tarjeta LGT8F328P; 


# Identificación tarjeta ATmega328P

## Vista
![Alt text](Imagenes/LGT8F328P/LGT8F328P.jpg)

## Hoja de datos
[LGT8F328P](https://wolles-elektronikkiste.de/en/lgt8f328p-lqfp32-boards)




# Configuración general

Se integran las funciones básicas del microcontrolador para generar una estructura hardware general, asi;

- 7 pwms
- 1 puerto de comunicación
- 20 entradas/salidas digitales 
- 8 entradas análogas

*visualización en PSoC creator*

![!\[Alt text\](Esquema_Electrico_LGT8F328P.jpg)](Imagenes/LGT8F328P/Esquema_Electrico_LGT8F328P.jpg)

## Identificación de puertos
A continuación se muestran los puertos que se usan y sus debidos nombramientos para la programación: 

No Pin| Nombre |Función  |
----|----------|--------------|
0   |d0   (RXD) |Pin Digital / Recepción UART|
1   |d1   (TXD) |Pin Digital / Transmisión UART| 
2   |d2      |Pin Digital| 
3   |d3   (PWM) |Pin Digital / PWM|
4   |d4      |Pin Digital|
5   |d5   (PWM)  |Pin Digital / PWM|
6   |d6   (PWM)  |Pin Digital / PWM|
7   |d7      |Pin Digital|
8   |d8      |Pin Digital|
9   |d9   (PWM) |Pin Digital / PWM|
10  |d10  (PWM) |Pin Digital / PWM|
11  |d11  (PWM) |Pin Digital / PWM|
12  |d12       |Pin Digital|
13  |d13       |Pin Digital|
14  |d14   a0  |Pin Digital / Pin Analógico|
15  |d15   a1  |Pin Digital / Pin Analógico|
16  |d16   a2  |Pin Digital / Pin Analógico|
17  |d17   a3  |Pin Digital / Pin Analógico|
18  |d18   a4  |Pin Digital / Pin Analógico|
19  |d19   a5  |Pin Digital / Pin Analógico|
20  |d20   a6  |Pin Digital / Pin Analógico|
21  |d21   a7  |Pin Digital / Pin Analógico|
22  |d22       |Pin Digital|
23  |d23       |Pin Digital|
25  |d25   a10   (AREF) |Pin Digital / Pin Analógico / Referencia Analógica|
    |GND      |Pin Tierra|
    |VIN  |Tensión de entrada Nominal 7-12 V|
    |RST  |Reset|
    |5 V   |Voltaje de E/S|
    |3.3 V |Voltaje de E/S|




hola

## Programación en lenguaje v

### Configuración puertos de salida

Para activar el puerto que va ha usar;
```go
pin_high(pin_name)
```
*Ejemplo: Si se desea activar el puerto do0;  `pin_high(do0)`.*

Para desactivar el puerto que se está usando;
```go
pin_low(pin_name)
```
*Ejemplo: Si se desea desactivar el puerto do0;  `pin_low(do0)`.*

Para desactivar o activar el puerto que se va ha usar;

```go
pin_write(pin_name, value)
```
*Ejemplo: Si se desea desactivar el puerto do0;  `pin_write(do0, 1)`, y si se desea activar;  `pin_write(do0, 0)`.*

### Detección puertos de entrada

Si se necesita saber en que estado esta un puerto de entrada:
```go
x = pin_read(pin_name)
```

*Ejemplo: Si se desea detectar el valor del puerto di0; `x = pin_read(di0)`, y x tomara el valor de 0 o 1, dependiendo el puerto es activo o desactivado.*

### Puertos análogos a digital (ADC)

Para configurar uno de los puertos análogos;
```go
adc_setup(channel, setup_value_1, ... )
```
*En channel se introduce el nombre del puerto análogo, en setup_value_1 el valor que se le va ha dar ha dicho puerto.*

Para detectar el valor del puerto análogo;
```go
x = adc_read(channel)
```
*En channel se introduce el nombre del puerto análogo, y x toma el valor que tenga dicho puerto.*

### PWM

Para configurar algún pwm;
```go
pwm_setup(pwm_id, setup_value_1, ... )
```
*En pwm_id se pone el pwm a usar,  y en setup_value_1 el valor al cual se desea configurar dicho pwm.*


Ahor, para configurar el ciclo de trabajo de un modulador;
```go
pwm_duty(pwm_id, duty)
```
*En pwm_id se pone el pwm a usar,  y en duty el valor del ciclo (de 0 a 100) en porcentaje.*

### Serial comunication (UART)

Para configurar un puerto UART;
```go
uart_setup(uart_id, baud_rate)
```
*Aquí uart_id es el nombre del puerto que se va ha usar, y baud_rate es el valor de los baudios al cual se va ha usar.*

Si se requiere ingresar un valor a un puerto UART;
```go
x = uart_input(uart_id)
```
*Donde x es dicho valor.*

En el caso de que se necesite tomar un valor del puerto UART que se esta usando;

-Forma lineal
```go
uart_println(uart_id, message)
```
*Muestra el mensaje (message) de tal forma que un carácter sigue al otro.*

-Forma no lineal
```go
uart_print(uart_id, message)
```
*Muestra el mensaje (message) con saltos de renglon.*

### Retardos

Uso de tiempos;

-Segundos
```go
sleep(s)
```
-milisegundos

```go
sleep_ms(ms)
```


-Microsegundos

```go
sleep_us(us)
```
*En cada expresión, el valor del tiempo se pone dentro del parentesis.*

Ejemplo LED parapadeante

```go
import machine { pin }
import time { sleep_ms }

pin_mode(led1, out)

for {   //infinite loop
    pin_high(led1)
    sleep_ms(500)
    pin_low(led1)
    sleep_ms(500)
}
```