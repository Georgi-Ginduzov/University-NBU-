#pragma once
#include <string>

	using namespace std;

		class web_link
		{
		private: //Attributes
			string content;
			char* textQR;

		public:
			web_link();
			web_link(char* linkQR, string content);
			web_link(string linkcontent) :content(linkcontent) {}
			~web_link();



		};