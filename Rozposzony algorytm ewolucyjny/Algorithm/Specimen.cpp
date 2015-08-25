#include "Specimen.hpp"



namespace Algorithm
{
		Specimen::Specimen()
		{
			generation = 0;
		}

		Specimen::Specimen(std::istringstream & ss)
		{
			int temp;
			ss>>temp;

			ss>>value;
			ss>>generation;
			track.resize(temp);

			for (int i=0; i<temp; i++)
				ss>>track[i];

		}

//		Specimen::Specimen(std::istringstream & ss, boost::shared_ptr<AlgorithmInformation> z)
//		{
//			algorithmInformation = z;
//
//			generation = 1;
//			int cities = algorithmInformation->getNumberOfCities();
//			track.resize(cities);
//
//			for (int i=0; i<cities; i++)
//			{
//				ss>>track[i];
//			}
//
//			countValue();
//
//			std::cout<< "Utworzylem ";
//			for (int i=0; i<cities; i++)
//				std::cout<< track[i] << " ";
//			std::cout<<std::endl;
////			track.resize(3);
////
////			for (int i=0; i<3; i++)
////				ss>>track[i];
////
////			std::cout<<"Utworzylem Speciena z danych: ";
////			std::cout<<track[0]<< " " << track[1] << " " << track[2] << std::endl;
////			//std::cout<< "poczatek3" << std::endl;
////			ss>>info;
////			std::cout<<"Utworzylem Speciena z danych: "<<info.c_str()<<std::endl;
//			//info=data;
//			//data.clear();
//		}

//		Specimen::Specimen(const Speciment$ old)
//		{
//
//		}

		Specimen::Specimen(std::vector<int>* toPut, boost::shared_ptr<AlgorithmInformation> z)
		{
			algorithmInformation = z;

			track.reserve(algorithmInformation->getNumberOfCities());

			track = *toPut;

			countValue();


		}

		std::string Specimen::getInfo()
		{
			std::string info;
			int cities = algorithmInformation->getNumberOfCities();

			info += ' ';
			info += cities;
			info += ' ';
			info += value;
			for (int i=0;i<cities;i++)
			{
				info += ' ';
				info += track[i];

			}


			return info;
		}

		int Specimen::getValue()
		{
			return value;
		}

		const int Specimen::getGeneration()
		{
			return generation;
		}

		void Specimen::setGeneration(const int s)
		{
			generation = s;
		}

		void Specimen::serialize(std::ostringstream &os)
		{
			os<<' ';
			int cities = algorithmInformation->getNumberOfCities();
			os<<cities;

			os << ' ';
			os << value;
			os << ' ';
			os << generation;
			for (int i=0; i<cities;i++)
			{
				os<<' ';
				os<<track[i];
			}
			
		}

		std::list<int> Specimen::getTrack()
		{
			int temp = track.size();
			std::list<int> toSend;

			for (int i=0; i<temp; i++)
				toSend.push_back( track[i] );

			return toSend;
		}

		std::vector<int>* Specimen::getTrackForDead()
		{
			return &track;
		}

		void Specimen::putTrack(std::vector<int>* from)
		{
			track = *from;
		}

		void Specimen::countValue()
		{
			int cities = track.size();
			int temp = 0;
			bool ifPossible = false;


			for (int i=0; i<cities; i++)
			{

					ifPossible = true;
					temp += algorithmInformation->getDistance(track[i], track[(i+1)%cities]);



			}

			value = temp;

		}

		//inwersja - zamiana kolejnosci odwiedzanych miast
		void Specimen::mutation(int first, int second)
		{

			int half = (second - first + 1)/2;
			int tempvalue;

			for (int i=0; i<half; i++)
			{
				tempvalue = track[first+i];
				track[first+i] = track[second-i];
				track[second-i] = tempvalue;
			}

			countValue();


		}

		void Specimen::crossing(std::list<int> to, int first, int second)
		{
			int cities = algorithmInformation->getNumberOfCities();

			std::list<int>::iterator it;


			//usuwanie z listy miast których kolejnosc nie ulega zmianie
			for (int z=first; z<second; z++)
			{
				it = to.begin();
				for(int j=0; j<cities; j++)
				{
					if ( *it == track[z])
						{
							to.erase(it);
							break;
						}
					else
						it++;
				}
			}

			for (int i=second; i<cities; i++)
			{
				track[i] = to.front();
				to.pop_front();
			}

			for (int i=0; i<first; i++)
			{
				track[i] = to.front();
				to.pop_front();
			}

			countValue();
			generation++;

		}

		void Specimen::setAlgorithmInformation(boost::shared_ptr<AlgorithmInformation> toSet)
		{
			algorithmInformation = toSet;
		}
}
