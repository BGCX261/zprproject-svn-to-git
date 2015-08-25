//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Algorithm.cpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#include "Algorithm.hpp"


namespace Algorithm {

	Algorithm::Algorithm()
	{
		numberOfSpeciments = 6;
		sizeOfPutList = 3;
		interval = 10;
		probabilityOfMutation = 7;
		stepBetweenIntervals = 1;
		sizeOfDeque = 5;
		//bestValue = 0;
		//lastBestValue = 0;
		step = 1;

//		std::string citi ("5 2 5 4 5 1 3 7 3 4 7");
//		algorithmInformation = boost::shared_ptr<AlgorithmInformation>(new AlgorithmInformation(citi));
		aleatory = std::auto_ptr<Random>(new Random());
	}

	void Algorithm::run() {
	//char ch[255];
	createList();	//tworzenie pierwszego pokolenia osobnikow


		while(!isInterrupted())
		{
			getNextGeneration();	//tworzenie kolejnego pokolenia
			
		}
	
	}
	

	
	Creator* Algorithm::getCreateSpecimenFun()
	{
		specimentCreator = boost::shared_ptr<SpecimentCreator>(new SpecimentCreator());
		return specimentCreator.get();
	}
	
	std::list<AbstractSpecimen*> Algorithm::getSpeciments()
	{
		enter();
		if (getDeque.size() == 0)
			wait(emptyGetDeque);

		std::list<AbstractSpecimen*> toSend;

		toSend = getDeque.front();
		getDeque.pop_front();

		leave();
		return toSend;
	}
	
	void Algorithm::putSpeciments(std::list<AbstractSpecimen*> list)
	{
		enter();
		if ( putDeque.size() == sizeOfDeque) wait(fullPutDeque);

		putDeque.push_back(list);
		leave();


	}
	
	void Algorithm::setTask(Task *task)
	{
		std::string temp = (task->getTask());
		algorithmInformation = boost::shared_ptr<AlgorithmInformation>(new AlgorithmInformation(temp));

		delete task;


	}

	void Algorithm::setNumberOfSpecimen(const int numer)
	{
		enter();
		numberOfSpeciments = numer;
		leave();
	}
	
	int Algorithm::getNumberOfSpeciment()
	{
		int temp;
		enter();
		temp = numberOfSpeciments;
		leave();
		return temp;
	}
	
	void Algorithm::setInterval(const int interval)
	{
		enter();
		this->interval = interval;
		leave();
	}

	int Algorithm::getInterval()
	{
		int temp;
		enter();
		temp = interval;
		leave();
		return temp;
	}
	
	void Algorithm::setSizeOfPutList(const int size)
	{
		enter();
		sizeOfPutList = size;
		leave();
	}
	
	const int Algorithm::getSizeOfPutList()
	{
		int temp;
		enter();
		temp = sizeOfPutList;
		leave();
		return temp;
	}
	
	int Algorithm::getProbabilityOfMutation()
	{
		int temp;
		enter();
		temp = probabilityOfMutation;
		leave();
		return temp;
	}

	void Algorithm::setProbabilityOfMutation(const int probability)
	{
		enter();
		if (probability < 100 && probability >=0)
			probabilityOfMutation = probability;
		leave();
	}

	const unsigned Algorithm::getSizeOfDeque()
	{
		int temp;
		enter();
		temp = sizeOfDeque;
		leave();
		return temp;
	}

	void Algorithm::setSizeOfDeque(const unsigned size)
	{
		enter();
		sizeOfDeque = size;
		leave();
	}

	void Algorithm::putToGetDeque()
	{
		enter();
		if (getDeque.size() < sizeOfDeque)
		{
			std::list<Specimen*>::iterator it;
			std::list<AbstractSpecimen*> temp;

			it = listOfSpeciments.begin();
			for (int i=0; i<sizeOfPutList; i++)
			{
				Specimen* _new = new Specimen((*(*it)));
				temp.push_back(static_cast<AbstractSpecimen*>(_new));
				it++;
			}
			getDeque.push_back(temp);
		}

		signal(emptyGetDeque);
		leave();
	}

	void Algorithm::getFromPutDeque()
	{
		enter();
		if (putDeque.empty() != true)
		{
			std::list<AbstractSpecimen*> temp;
			temp = putDeque.front();
			putDeque.pop_front();

			while (temp.size() > 0)
			{
				listOfSpeciments.push_front(static_cast<Specimen*>(temp.back()));
				listOfSpeciments.front()->setAlgorithmInformation(algorithmInformation);

				delete temp.back();
				temp.pop_back();
			}

			sortSpeciments();
		}

		signal (fullPutDeque);
		leave();
	}

	void Algorithm::orderCrossover(Specimen* first, Specimen* second)
	{

		int cities = algorithmInformation->getNumberOfCities();
		int _rand;

		int firstCut = aleatory->getRandom(cities);

		int secondCut =  aleatory->getRandom(firstCut, cities-1);



		std::list<int> fromFirst = first->getTrack();
		std::list<int> fromSecond = second->getTrack();

		first->crossing(fromSecond, firstCut, secondCut);
		second->crossing(fromFirst, firstCut, secondCut);


		_rand = aleatory->getRandom(99);

// czy ma dojść do mutacji której prawdopodobieństwo jest wartością
// zmiennnej probabilityOfMutation
		if (_rand < probabilityOfMutation)
			mutation(first);

		_rand = aleatory->getRandom(99);

		if (_rand < probabilityOfMutation)
					mutation(second);
	}

	/*
	 * mutacja obiektu - losowo wybierane sa dwa ciecia pomiedzy
	 * ktorymi kolejnosc miast zostanie zamieniona
	 */
	void Algorithm::mutation(Specimen* first)
	{
		int cities = algorithmInformation->getNumberOfCities();

		int firstCut = aleatory->getRandom(cities);

		int secondCut = aleatory->getRandom(firstCut, cities-1);

		first->mutation(firstCut, secondCut);
	}

	//sortowanie listy osobnikow tak by najlepsze byly na jej poczatku
	void Algorithm::sortSpeciments ()
	{
		listOfSpeciments.sort( std::greater< Specimen* >() );

		std::list<Specimen*>::iterator it;
		it = listOfSpeciments.begin();
		std::cout<<"posortowano ";
		for (unsigned i=0; i<listOfSpeciments.size(); i++)
		{
			std::cout<<" " << (*it)->getValue();
			it++;
		}
		std::cout<<std::endl;
	}

	void Algorithm::createList()
	{
		enter();
		for (int i=0; i<numberOfSpeciments; i++)
		{
			listOfSpeciments.push_front(createSpecimen());
		}
		leave();
		sortSpeciments();
	}

	Specimen* Algorithm::createSpecimen()
	{
		int _rand;
		std::list<int> listOfCities;
		std::list<int>::iterator it;
		int cities = algorithmInformation->getNumberOfCities();
		std::vector<int> _track;
		_track.resize(cities);

		for (int i=0; i<cities; i++)
			listOfCities.push_back(i);

		for (int j=0; j<cities-1; j++)
		{
			_rand = aleatory->getRandom(cities-j);

			it = listOfCities.begin();

			for (int z=0; z<_rand;z++)
				it++;

			_track[j] = *it;
			listOfCities.erase(it);

		}
		_track[cities-1] = listOfCities.front();

		return new Specimen(&_track, algorithmInformation);
	}

	void Algorithm::getNextGeneration()
	{
		enter();
		int _numberOfSpeciments = numberOfSpeciments;
		leave();

		int temp = (int)listOfSpeciments.size();
		if ( temp > _numberOfSpeciments)
		{
			Specimen *_delete;
			while (temp>_numberOfSpeciments)
			{
				_delete = listOfSpeciments.back();
				listOfSpeciments.pop_back();
				--temp;
				delete _delete;

			}
		}
		else if (temp < _numberOfSpeciments)
		{
			while (temp<_numberOfSpeciments)
			{
				listOfSpeciments.push_back(createSpecimen());
				++temp;
			}
		}

//ile osobnikow najlepszych ma przejsc do nastepnej generacji
		int toSurvive = aleatory->getRandom(_numberOfSpeciments/20 + 1, _numberOfSpeciments/4);

		std::list<Specimen*>::iterator surviveArea;
		std::list<Specimen*>::iterator deadArea;

		surviveArea = listOfSpeciments.begin();

		deadArea = listOfSpeciments.end();
		--deadArea;

		//wartosci najlepszych osobnikow kopiowane sa w miejsce
		//najgorzej przystosowanych 2 krotnie
		for (int z=0; z<2; z++)
		{
		for (int i=0; i<toSurvive; i++)
		{
			(*deadArea)->putTrack((*surviveArea)->getTrackForDead());

			(*deadArea)->setGeneration((*surviveArea)->getGeneration());
			--deadArea;
			++surviveArea;
		}
		}

		/*
		 * iteratory do krzyzowania osobnikow
		 * krzyzowanie zaczyna sie od osobnikow za poprzednio najlepszymi osobnikami
		 * ktore wezma udzial w dalszej reprodukcji bez zmiaz oraz po przez skopiowanie
		 * ich genotypu najgorszym osobnikom beda uczesniczyc w krzyzowaniu
		 *
		 * deadArea-uzywany do zabezpieczenia sie przed wyjsciem po za zakres listy
		 */
		std::list<Specimen*>::iterator first;
		std::list<Specimen*>::iterator second;

		deadArea = listOfSpeciments.end();
		deadArea--;

		first = surviveArea;

		while((first != deadArea) && (first != listOfSpeciments.end()))
		{
			second = first;
			++second;

			orderCrossover(*first, *second);


			++first;
			++first;
		}


		/*
		 * sortowanie osobnikow tak zeby na pierwszych pozycjach byly najlepiej przystosowane
		 */
		sortSpeciments();

		/*
		 * co iles (okreslona ilosc przez zmienna interval) nastepuje wstawianie
		 * do kolejki getDeque kopii najlepszych osobnikow oraz pobieranie z
		 * kolejki otrzymanych osobnikow z putDeque
		 */
		if (stepBetweenIntervals == 0)
		{
			putToGetDeque();

			getFromPutDeque();
		}

		stepBetweenIntervals = (stepBetweenIntervals + 1)%interval;
	}

}
