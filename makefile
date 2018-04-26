onda.pdf : datos.txt graf.py
	python graf.py
datos.txt : onda.cpp
	c++ onda.cpp -o onda
	./onda > datos.txt
