# IBM-hackathon

Pretendemos realizar un modelo de prevención de infartos para residencias de ancianos y hospitales.

Para ello, en primer lugar se parten de dos datasets iniciales, en los cuales hay una serie de registros con variables que pueden ser determinantes para el estudio. Haciendo un primer análisis de los estos, se deciden eliminar aquellas variables que no son características.
A partir de aquí se realizan una serie de transformaciones para que ambos datasets sean homogéneos (en cuanto a las variables se refiere).

Tras estas transformaciones, obtenemos otros dos nuevos datasets: people y adults. La principal diferencia es que "adults" solo contempla los registros de los pacientes a partir de una edad significativa.

Finalmente, se decide el modelo predictivo con el que la confianza de acierto es mayor y la aplicamos sobre nuestro dataset.

En la práctica, el/los paciente/pacientes llevarán una pulsera con un sensor de temperatura y otro de pulso. Estas variables se recogerán de forma continua y sólo cuando se observen valores fuera de lo normal en el pulso, entraremos en el modelo de predicción y, con las características del paciente en cuestión, prediciremos si tiene un alto factor de infarto, o si, por el contrario, esta alteración solo se ha debido a alguna otra causa, como puede ser estrés o un esfuerzo físico mayor de lo habitual.
