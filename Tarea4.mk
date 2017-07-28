PuntoNemo.pdf : plots.py datos.txt
	python plots.py
datos.txt : a.out
	./a.out 

a.out: GeographicPoint.c
	gcc GeographicPoint.c -lm
	
clean: 
	rm *.out datos.txt *.pdf
