PuntoNemo.pdf : Plots.py datos.txt
	python Plots.py
datos.txt : a.out
	./a.out 

a.out: GeographicPoint.c
	gcc GeographicPoint.c -lm
	
clean: 
	rm *.out datos.txt *.pdf
