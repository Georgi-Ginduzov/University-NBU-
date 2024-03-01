#include <iostream>
#include <string>
#include <list>

using namespace std;

struct YouTubeChannel {
	string Name;
	int SubscribersCount;

	YouTubeChannel(string name, int subscribersCount) {
		Name = name;
		SubscribersCount = subscribersCount;
	}

	bool operator==(const YouTubeChannel& channel) const{ //the function will not change its parameters
		return this->Name == channel.Name;
	}
};

struct MyCollection {
	list<YouTubeChannel>myChannels;

	void operator+= (YouTubeChannel& channel) {
		this->myChannels.push_back(channel);
	}
	void operator-= (YouTubeChannel& channel) {
		//this->myChannels.pop_back();
		this->myChannels.remove(channel);//gives error because remove() can't 
		//compare two objects 
		// solution is to overload the == operator
	}
};

ostream& operator<<(ostream& COUT, YouTubeChannel& ytChannel) { 
	//pass the original object with & not a copy
	COUT << "Name: " << ytChannel.Name << endl;
	COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;

	//print multiple objects make this function return ostream object
	//therefore instead of "void operator << (ostream& COUT, ..."
	//use "ostream& operator << (ostream& COUT, ..." and then "return COUT"

	return COUT;

}	

//overloada cout for list datatype(MyCollection)	
ostream& operator<<(ostream& COUT, MyCollection& myCollection) {
	for (YouTubeChannel ytChannel : myCollection.myChannels)
	{
		COUT << ytChannel << endl;
	}
	return COUT;
}

int main() {
	YouTubeChannel yt1 = YouTubeChannel("CodeBeauty", 75000);
	YouTubeChannel yt2 = YouTubeChannel("My second channel", 80000);
	
	cout << yt1;

	//another way to invoke the "ostream& operator << .." function as regular function
	operator <<(cout, yt1);
	cout << "\n\n\n";

	//overload += operator line 17
	MyCollection myCollection;
	myCollection += yt1; //yt1 will be added to the list of channels
	myCollection += yt2;
	
	cout << myCollection;

	//overload -= operator line 17
	myCollection -= yt2;

	cout << myCollection;



	return 0;
}