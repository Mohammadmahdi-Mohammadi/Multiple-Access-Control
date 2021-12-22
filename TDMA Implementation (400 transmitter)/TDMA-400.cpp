
#include <iostream>
#include <time.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <random>

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
	transmitter(int, int);
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

transmitter::transmitter(int size, int rate)
{
	data_rate = rate;
	size_of_available_data_to_send = size;
	flag_for_last_success = -1;
	data_array = new int[size];
	check_list_array = new bool[size];
	for (int i = 0; i < size_of_available_data_to_send; i++) {
		check_list_array[i] = false;
	}
	for (int i = 0; i < size; i++)
		data_array[i] = rand() % 2;


}

transmitter::transmitter(int size, int rate, int order)
{
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
	//int A, B, C, D , F;
	//bool A_check, B_check, C_check, D_check = false;
	int capacity;
	int number_of_transmitters;
	int time_slots_till_this_moment;
	transmitter* transmitters_array;
	//transmitter* Applicants_for_submission;
public:
	Shared_channel_TDMA(int);
	Shared_channel_TDMA(int, transmitter, transmitter, transmitter, transmitter);
	void channel_engine();
	int ramain_data_for_all_tranmitters();
	int get_time_slots();
	int remain_special_tranmitter(int);
	//void check_transmitters();
	transmitter get_array(int);
	int Set_priorities_for_sending();
	void using_the_channel(int);
	void channel_summary();

};

Shared_channel_TDMA::Shared_channel_TDMA(int _input)
{
	cout << "Vared" << endl;
	capacity = 30;
	number_of_transmitters = 400;
	time_slots_till_this_moment = 0;
	transmitters_array = new transmitter[400];
	for (int i = 0; i < 400; i++) {
		if (i < 100) {
			transmitter temp(110, 5);
			transmitters_array[i] = temp;
		}
		if (i >= 100 && i < 200) {
			transmitter temp(75, 3);
			transmitters_array[i] = temp;
		}
		if (i >= 200 && i < 300) {
			transmitter temp(94, 2);
			transmitters_array[i] = temp;
		}
		if (i >= 300 && i < 400) {
			transmitter temp(60, 4);
			transmitters_array[i] = temp;
		}
	}

	for (int i = 0; i < 400; i++)
		cout << i << "  " << transmitters_array[i].get_size() << "		" << transmitters_array[i].get_data_rate() << endl;

}

Shared_channel_TDMA::Shared_channel_TDMA(int _capacity, transmitter first, transmitter second, transmitter third, transmitter fourth)
{
	capacity = _capacity;
	number_of_transmitters = 4;
	transmitters_array = new transmitter[number_of_transmitters];
	transmitters_array[0] = first;
	transmitters_array[1] = second;
	transmitters_array[2] = third;
	transmitters_array[3] = fourth;

}

void Shared_channel_TDMA::channel_engine()
{
	int counter = 0;
	int Correction;

	while (ramain_data_for_all_tranmitters() > 0) {

		cout << "reamin data in all the transmitters is: " << ramain_data_for_all_tranmitters() << endl;

		cout << endl << endl << "the channel is going to provide the time slot number : " << time_slots_till_this_moment << endl << endl;
		int sender_index = Set_priorities_for_sending();
		using_the_channel(sender_index);

		counter++;
		//cout << "the counter is : " << counter << endl << endl << endl;

		//cout << "node A remain data is " << remain_special_tranmitter(0) << endl;
		//cout << "node B remain data is " << remain_special_tranmitter(1) << endl;
		//cout << "node C remain data is " << remain_special_tranmitter(2) << endl;
		//cout << "node D remain data is " << remain_special_tranmitter(3) << endl;
	}
	cout << "all the tranmitters send their data successfully after " << time_slots_till_this_moment << " timeslots" << endl;
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

transmitter Shared_channel_TDMA::get_array(int _index)
{
	return transmitters_array[_index];
}

int Shared_channel_TDMA::Set_priorities_for_sending()
{

	//if (transmitters_array[0].ramain_data() == 0 && A_check == false) {
	//	A = time_slots_till_this_moment - 1 ;
	//	A_check = true;
	//}		
	//if (transmitters_array[1].ramain_data() == 0 && B_check == false) {
	//	B = time_slots_till_this_moment - 1 ;
	//	B_check = true;
	//}
	//if (transmitters_array[2].ramain_data() == 0 && C_check == false) {
	//	C = time_slots_till_this_moment - 1;
	//	C_check = true;
	//}
	//if (transmitters_array[3].ramain_data() == 0 && D_check == false) {
	//	D = time_slots_till_this_moment - 1;
	//	D_check = true;
	//}

	int sum_of_data = 0;

	for (int i = 0; i < 400; i++) {
		sum_of_data += transmitters_array[i].ramain_data();
	}

	int Previous_interval = 0;
	int random_nubmer = rand() % sum_of_data;
	cout << "sum of remain data is  " << sum_of_data << endl;
	cout << "random number is  " << random_nubmer << endl;
	for (int i = 0; i < 400; i++) {
		if (random_nubmer >= Previous_interval &&  random_nubmer < (Previous_interval + transmitters_array[i].ramain_data()))
			return i;
		Previous_interval = Previous_interval + transmitters_array[i].ramain_data();
	}

	cout << "non of the if conditions dosnt work ! " << endl;
}

void Shared_channel_TDMA::using_the_channel(int _sender_node)
{
	time_slots_till_this_moment++;

	cout << "current node for sending is :" << _sender_node << endl;
	if (transmitters_array[_sender_node].ramain_data() > 0) {
		cout << "this node have data to send " << endl;

		if (transmitters_array[_sender_node].probability_to_send()) {
			cout << "the node requests to send data" << endl;
			transmitters_array[_sender_node].set_check_list_array();
			cout << "the node sends data successfully based on data rate" << endl;
			transmitters_array[_sender_node].flag_Increase();
			cout << "flag of last success for this node increased based on data rate " << endl;

		}

		else
			cout << "the node has no request to send and channel missed this timeslot ! " << endl;
	}
	else
		cout << "this node dsnt have any data to send " << endl;



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
;

int main() {


	cout << "hellooo" << endl;

	Shared_channel_TDMA single_channel(5);


	//cout << single_channel.ramain_data_for_all_tranmitters() << endl;

	//	C.print_transmitter();

	//	cout << "node C remain data is " << single_channel.remain_special_tranmitter(2) << endl;


	//cout << single_channel.get_time_slots() << endl;
	single_channel.channel_engine();
	//cout << "node A remain data is " << single_channel.remain_special_tranmitter(0) << endl;
	//cout << "node B remain data is " << single_channel.remain_special_tranmitter(1) << endl;
	//cout << "node C remain data is " << single_channel.remain_special_tranmitter(2) << endl;
	//cout << "node D remain data is " << single_channel.remain_special_tranmitter(3) << endl;

	//single_channel.channel_summary();



	int sd;
	cin >> sd;





}


