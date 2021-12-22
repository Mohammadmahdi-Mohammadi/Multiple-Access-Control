
#include <iostream>
#include <time.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <random>
#include <cstdlib>
#include <ctime>




using namespace std;
//Transmitters are devices that are used to send out
//data as radio waves in a specific band of the electromagnetic
//spectrum in order to fulfill a specific communication need, 
//be it for voice or for general data.In order to do this, a transmitter
//takes energy from a power source and transforms this into a radio frequency
//alternating current that changes direction millions to billions of times per
//second depending on the band that the transmitter needs to send in.When this 
//rapidly changing energy is directed through a conductor, in this case an antenna, 
//electromagnetic or radio waves are radiated outwards to be received by another antenna
//that is connected to a receiver that reverses the process to come up with the actual message or data.
class transmitter {
	//A transmitter is an electronic device used in telecommunications 
	//to produce radio waves in order to transmit or send data with the
	//aid of an antenna. The transmitter is able to generate a radio frequency 
	//alternating current that is then applied to the antenna, which, in turn, 
	//radiates this as radio waves. There are many types of transmitters depending
	//on the standard being used and the type of device; for example, many modern devices
	//that have communication capabilities have transmitters such as Wi-Fi, Bluetooth, NFC and cellular.
private:
	int size_of_available_data_to_send;
	int flag_for_last_success;
	bool* check_list_array;
	int* data_array;
	int data_rate;				// the number of bits to send in each time_slot
public:
	transmitter();
	transmitter(int, int, int);
	int  get_size();
	int  get_flag_num();
	bool  get_data_check(int);
	int  get_data(int);
	int  get_data_rate();
	void set_flag(int);
	void set_check_list_array();
	bool probability_to_send();
	void read_data_to_itilize_array(int);
	int ramain_data();
	void flag_Increase();
	void print_transmitter();
};

transmitter::transmitter()
{

}

transmitter::transmitter(int size, int rate, int order)
{
	//srand(time(NULL));
	size_of_available_data_to_send = size;
	flag_for_last_success = -1;
	data_array = new int[size];
	check_list_array = new bool[size];
	data_rate = rate;
	read_data_to_itilize_array(order);
	for (int i = 0; i < size_of_available_data_to_send; i++) {
		check_list_array[i] = false;
	}
}



int transmitter::get_size()
{
	return size_of_available_data_to_send;
}

int transmitter::get_flag_num()
{
	return flag_for_last_success;
}

bool transmitter::get_data_check(int input)
{
	return check_list_array[input];
}

int transmitter::get_data(int input)
{
	return data_array[input];
}

int transmitter::get_data_rate()
{
	return data_rate;
}

void transmitter::set_flag(int input)
{
	flag_for_last_success = input;
}

void transmitter::set_check_list_array()
{
	for (int i = 0; i < data_rate; i++) {

		check_list_array[flag_for_last_success + i] = true;
	}
}

bool transmitter::probability_to_send()
{
	if (rand() % 2 == 0)
		return true;
	return false;
}

void transmitter::read_data_to_itilize_array(int _order)
{
	if (_order == 1) {
		ifstream data;
		data.open("A.txt");
		for (int i = 0; i <= size_of_available_data_to_send; i++) {
			int input;
			data >> input;
			data_array[i] = input;
		}
		data.close();
	}
	if (_order == 2) {
		ifstream data;
		data.open("B.txt");
		for (int i = 0; i < size_of_available_data_to_send; i++) {
			int input;
			data >> input;
			data_array[i] = input;
		}
		data.close();
	}
	if (_order == 3) {
		ifstream data;
		data.open("C.txt");
		for (int i = 0; i < size_of_available_data_to_send; i++) {
			int input;
			data >> input;
			data_array[i] = input;
		}
		data.close();
	}
	if (_order == 4) {
		ifstream data;
		data.open("D.txt");
		for (int i = 0; i < size_of_available_data_to_send; i++) {
			int input;
			data >> input;
			data_array[i] = input;
		}
		data.close();
	}
}

int transmitter::ramain_data()
{
	return (size_of_available_data_to_send - flag_for_last_success) - 1;
}

void transmitter::flag_Increase()
{
	flag_for_last_success = flag_for_last_success + data_rate;
}

void transmitter::print_transmitter()
{
	for (int i = 0; i < size_of_available_data_to_send; i++)
		cout << "index number " << i << " is " << data_array[i] << endl;
}

//____________________________________________________________________________

class Shared_channel_TDMA {
	//Time-division multiple access (TDMA) is a channel access method for shared-medium networks.
	//It allows several users to share the same frequency channel by dividing the signal into different 
	//time slots.[1] The users transmit in rapid succession, one after the other, each using its own time slot.
	//This allows multiple stations to share the same transmission medium (e.g. radio frequency channel) while 
	//using only a part of its channel capacity. TDMA is used in the digital 2G cellular systems such as Global System 
	//for Mobile Communications (GSM), IS-136, Personal Digital Cellular (PDC) and iDEN, and in the Digital Enhanced Cordless
	//Telecommunications (DECT) standard for portable phones. TDMA was first used in satellite communication systems by Western
	//Union in its Westar 3 communications satellite in 1979. It is now used extensively in satellite communications,[2][3][4][5]
	//combat-net radio systems, and passive optical network (PON) networks for upstream traffic from premises to the operator.
	//For usage of Dynamic TDMA packet mode communication, see below.
private:
	//int A, B, C, D, F;
	//bool A_check, B_check, C_check, D_check = false;

	int failed = 0;
	int First_progress;
	int Second_progress;
	int Third_progress;
	int capacity;
	int number_of_transmitters;
	int time_slots_till_this_moment;
	transmitter* transmitters_array;
	//transmitter* Applicants_for_submission;
public:
	Shared_channel_TDMA(int, transmitter, transmitter, transmitter, transmitter);
	void channel_engine();
	int ramain_data_for_all_tranmitters();
	int get_time_slots();
	int remain_special_tranmitter(int);
	//void check_transmitters();
	void Set_priorities_for_sending();
	bool using_the_channel(int);
	void channel_summary();
	void check_trustable_data();
	void dynamic_additional(int);

};

Shared_channel_TDMA::Shared_channel_TDMA(int _capacity, transmitter first, transmitter second, transmitter third, transmitter fourth)
{
	capacity = _capacity;
	number_of_transmitters = 4;
	transmitters_array = new transmitter[number_of_transmitters];
	transmitters_array[0] = first;
	transmitters_array[1] = second;
	transmitters_array[2] = third;
	transmitters_array[3] = fourth;
	//First_progress, Second_progress, Third_progress, Fourth_progress = -1;
	First_progress = -1;
	Second_progress = -1;
	Third_progress = -1;





}

void Shared_channel_TDMA::channel_engine()
{
	int counter = 0;
	int Correction;
	srand(time(NULL));
	while (ramain_data_for_all_tranmitters() > 0) {

		cout << "reamin data in all the transmitters is: " << ramain_data_for_all_tranmitters() << endl;
		//First_progress, Second_progress, Third_progress, Fourth_progress = -1;

		cout << endl << endl << "the channel is going to provide the time slot number : " << time_slots_till_this_moment << endl;
		Set_priorities_for_sending();
		//cout << "##############" << endl;
		//cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;

		//int sender_index;

		//bool check1;
		//bool check2;
		//bool check = using_the_channel(First_progress);

		//if (!check) {
		//	check1 = using_the_channel(Second_progress);
		//	if (!check1) {
		//		using_the_channel(Third_progress);
		//		if (!using_the_channel(Third_progress))
		//			time_slots_till_this_moment++;
		//	}
		//}

		dynamic_additional(First_progress);





		//counter++;
		//cout << "the counter is : " << counter << endl << endl << endl;

		cout << "node A remain data is " << remain_special_tranmitter(0) << endl;
		cout << "node B remain data is " << remain_special_tranmitter(1) << endl;
		cout << "node C remain data is " << remain_special_tranmitter(2) << endl;
		cout << "node D remain data is " << remain_special_tranmitter(3) << endl;

		First_progress = -1;
		Second_progress = -1;
		Third_progress = -1;

	}
	cout << "all the tranmitters send their data successfully after " << time_slots_till_this_moment << " timeslots" << endl;
	//cout << "failed number is : " << failed << endl;
	//cout << "failed number is : " << counter << endl;
	//if (Correction == 0)
	//	A = counter;
	//if (Correction == 1)
	//	B = counter;
	//if (Correction == 2)
	//	C = counter;
	//if (Correction == 3)
	//	D = counter;


}

int Shared_channel_TDMA::ramain_data_for_all_tranmitters()
{
	int sum = 0;
	for (int i = 0; i < number_of_transmitters; i++)
		sum += transmitters_array[i].ramain_data();
	return sum;
}

int Shared_channel_TDMA::get_time_slots()
{
	return time_slots_till_this_moment;
}

int Shared_channel_TDMA::remain_special_tranmitter(int _tranmitter)
{
	return transmitters_array[_tranmitter].ramain_data();
}

void Shared_channel_TDMA::Set_priorities_for_sending()
{


	//cout << " here first progress is : " << First_progress << endl;
	//cout << " here second progress is : " << Second_progress << endl;
	//cout << " here third progress is : " << Third_progress << endl;


	int sum_of_data = 0;
	for (int i = 0; i < 4; i++) {

		sum_of_data += transmitters_array[i].ramain_data() / transmitters_array[i].get_data_rate();
	}

	//srand(time(NULL));
	int random_nubmer = rand() % sum_of_data;
	int previous_limit = 0;
	//int first_value = 0;

	cout << "Random number 1 is : " << random_nubmer << endl;


	while (First_progress == -1) {
		//		cout << "***************" << endl;

		for (int i = 0; i < 4; i++) {

			//	cout << " area number " << i << "is :  " << previous_limit << "	to	" << previous_limit + transmitters_array[i].ramain_data() / transmitters_array[i].get_data_rate() << endl;
			//cout << "area number "<< i << " is :" << previous_limit << "	to		"<< 
			//cout << i << "vared shod " << endl;

			if (random_nubmer >= previous_limit &&
				random_nubmer < (previous_limit + transmitters_array[i].ramain_data() / transmitters_array[i].get_data_rate())) {
				First_progress = i;
				//cout << i << "vared shod " << endl;
			}

			previous_limit += transmitters_array[i].ramain_data() / transmitters_array[i].get_data_rate();

		}
	}
	cout << "first is : " << First_progress << endl;



	//	//srand(time(NULL));
	random_nubmer = rand() % sum_of_data;

	Second_progress = (First_progress + 1) / number_of_transmitters;
	//previous_limit = 0;
	//cout << "Random number 2 is : " << random_nubmer << endl;
	//while (Second_progress == First_progress || Second_progress == -1 ) {
	//	//cout << "$$$$$$$$$$$$$$$$$" << endl;
	//	for (int i = 0; i < 4; i++) {

	//		if (random_nubmer >= previous_limit &&
	//			random_nubmer < previous_limit + transmitters_array[i].ramain_data() / transmitters_array[i].get_data_rate())
	//			Second_progress = i;
	//		previous_limit += transmitters_array[i].ramain_data() / transmitters_array[i].get_data_rate();
	//	}
	//	//cout << "second progress is : " << Second_progress << endl;
	//}
	//cout << "second progress is : " << Second_progress << endl;






	//srand(time(null));
	//random_nubmer = rand() % sum_of_data;
	//previous_limit = 0;
	////cout << first_progress;
	//cout << "random number 3 is : " << random_nubmer << endl;
	//while (Third_progress == First_progress || Third_progress == Second_progress || Third_progress == -1 ) {
	//	//cout << "888888888888888888888888888" << endl;
	//	for (int i = 0; i < 4; i++) {

	//		if (random_nubmer >= previous_limit &&
	//			random_nubmer < previous_limit + transmitters_array[i].ramain_data() / transmitters_array[i].get_data_rate())
	//			Third_progress = i;
	//		previous_limit += transmitters_array[i].ramain_data() / transmitters_array[i].get_data_rate();

	//	}
	//}


	int this_random = rand() % sum_of_data;

	Third_progress = (First_progress + 2) / number_of_transmitters;



	cout << "third progress is : " << Third_progress << endl;



	cout << " here first progress is : " << First_progress << endl;
	cout << " here second progress is : " << Second_progress << endl;
	cout << " here third progress is : " << Third_progress << endl;





}

bool Shared_channel_TDMA::using_the_channel(int _sender_node)
{
	//time_slots_till_this_moment++;

	cout << "current node for sending is :" << _sender_node << endl;
	if (transmitters_array[_sender_node].ramain_data() > 0) {
		cout << "this node have data to send " << endl;

		if (transmitters_array[_sender_node].probability_to_send()) {
			cout << "the node requests to send data" << endl;
			transmitters_array[_sender_node].set_check_list_array();
			cout << "the node sends data successfully based on data rate" << endl;
			transmitters_array[_sender_node].flag_Increase();
			time_slots_till_this_moment++;
			cout << "flag of last success for this node increased based on data rate " << endl;
			//time_slots_till_this_moment++;
			return true;

		}

		else {
			cout << "the node has no request to send and channel missed this timeslot ! " << endl;
			failed++;
			return false;
		}
	}
	else
	{
		cout << "this node dsnt have any data to send " << endl;
		failed++;

		return false;
	}



}

void Shared_channel_TDMA::channel_summary()
{
	cout << endl << "***********************************************" << endl;
	//cout << "Node A ends in timeslot number: " << A << endl;
	//cout << "Node B ends in timeslot number: " << B << endl;
	//cout << "Node C ends in timeslot number: " << C << endl;
	//cout << "Node D ends in timeslot number: " << D << endl;
	cout << "the number of all timeslots is : " << time_slots_till_this_moment << endl;
	cout << "***********************************************" << endl;


}

void Shared_channel_TDMA::check_trustable_data()
{
	cout << "first transmitter " << transmitters_array[0].ramain_data() << "	" << transmitters_array[0].get_data_rate() << endl;
	cout << "first transmitter " << transmitters_array[1].ramain_data() << "	" << transmitters_array[1].get_data_rate() << endl;
	cout << "first transmitter " << transmitters_array[2].ramain_data() << "	" << transmitters_array[2].get_data_rate() << endl;
	cout << "first transmitter " << transmitters_array[3].ramain_data() << "	" << transmitters_array[3].get_data_rate() << endl;

	cout << "first transmitter " << transmitters_array[0].ramain_data() / transmitters_array[0].get_data_rate() << endl;
	cout << "first transmitter " << transmitters_array[1].ramain_data() / transmitters_array[1].get_data_rate() << endl;
	cout << "first transmitter " << transmitters_array[2].ramain_data() / transmitters_array[2].get_data_rate() << endl;
	cout << "first transmitter " << transmitters_array[3].ramain_data() / transmitters_array[3].get_data_rate() << endl;



}

void Shared_channel_TDMA::dynamic_additional(int _index)
{
	if (_index == 0) {
		for (int i = 0; i < 2; i++) {
			if (transmitters_array[_index].ramain_data() > 0)
				using_the_channel(_index);
		}
	}

	if (_index == 1) {
		for (int i = 0; i < 3; i++) {
			if (transmitters_array[_index].ramain_data() > 0)
				using_the_channel(_index);
		}
	}

	if (_index == 2) {
		for (int i = 0; i < 5; i++) {
			if (transmitters_array[_index].ramain_data() > 0)
				using_the_channel(_index);
		}
	}
	if (_index == 3) {
		for (int i = 0; i < 2; i++) {
			if (transmitters_array[_index].ramain_data() > 0)
				using_the_channel(_index);
		}
	}
}

;

int main() {

	transmitter A(110, 5, 1);
	transmitter B(75, 3, 2);
	transmitter C(94, 2, 3);
	transmitter D(60, 4, 4);


	Shared_channel_TDMA single_channel(4, A, B, C, D);
	//cout << single_channel.ramain_data_for_all_tranmitters() << endl;

	//	C.print_transmitter();

	//	cout << "node C remain data is " << single_channel.remain_special_tranmitter(2) << endl;




	single_channel.channel_engine();


	//cout << single_channel.get_time_slots() << endl;
	//single_channel.Set_priorities_for_sending();



	//cout << "node A remain data is " << single_channel.remain_special_tranmitter(0) << endl;
	//cout << "node B remain data is " << single_channel.remain_special_tranmitter(1) << endl;
	//cout << "node C remain data is " << single_channel.remain_special_tranmitter(2) << endl;
	//cout << "node D remain data is " << single_channel.remain_special_tranmitter(3) << endl;

	//single_channel.check_trustable_data();
	//single_channel.channel_summary();



	int sd;
	cin >> sd;





}

