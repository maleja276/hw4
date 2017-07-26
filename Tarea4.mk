PuntoNemo.pdf : Plots.py datos.txt
	python Plots.py

datos.txt : a.out
	./a.out > datos.txt

a.out: GeographicPoint.c
	gcc GeographicPoint.c -lm
	
	
