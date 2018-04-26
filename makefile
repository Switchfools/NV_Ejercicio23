onda.png : Grafica.py onda.txt
	python3 Grafica.py
onda.txt : onda
	./onda>onda.txt
onda :Onda.cpp
	c++ Onda.cpp -o onda