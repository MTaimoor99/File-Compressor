#pragma once
#include "MyForm.h"
#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<bitset>
#include<fstream>
#include<unordered_map>
#include<map>
#include<sstream>
#include <msclr\marshal_cppstd.h>




struct node
{
	char c; //character in the string
	int f; //Frequency of character in the string
	node* next;
	node* left, * right; //left and right child of binary tree respectively

	node()
	{
		f = 0;
		left = NULL;
		right = NULL;
		c = NULL;
		next = NULL;


	}
};


struct compare {
public:
	bool operator()(node* a, node* b) // overloading both operators 
	{

		return a->f > b->f; //To maintain the order of min heap priority queue
	}
};
	
class HuffmanCoding
{
		std::vector<char> e;
		std::string filename; //The name of the file we want to encode
		std::string text; //The text that will be encoded
		std::priority_queue<node*, std::vector<node*>, compare> pq; //Priority queue that will contian characters of our string and their frequency
		std::string encoded;
		std::unordered_map <char, std::string> um;
	public:

		HuffmanCoding()
		{

			text = "";
			encoded = "";
		}

		void FileRead(System::String^ f)
		{
			filename = msclr::interop::marshal_as<std::string>(f);
			std::fstream readfile(filename, std::fstream::in);
			getline(readfile, text, '\0');
			readfile.close();
		}



		//Function which will calculate the frequency of characters in the string entered by the user
		void CharacterFrequency()
		{

			for (int i = 0; i < text.length(); i++)
			{
				int sum = 0;
				for (int j = 0; j < text.length(); j++)
				{

					if (j < i && text[i] == text[j])
					{
						break;
					}


					if (text[i] == text[j])
					{
						sum++;


					}



				}

				if (sum != 0)
				{
					PriorityQueue(text[i], sum);
				}
			}





		}

		// This will push our characters and their frequencies into our STL min heap priority queue
		void PriorityQueue(char ch, int freq)
		{

			node* n = new node; //pointer of type node is created
			n->c = ch; //Pointer stores character
			n->f = freq; //Pointer stores frequency of the character
			pq.push(n); //The node is pushed into the priority queue



		}

		//Will display the whole priority queue. All of the elements will be popped from it as a result.
		void PriorityQueueDisplay()
		{
			while (!pq.empty())
			{
				std::cout << (pq.top())->c << " " << (pq.top())->f << std::endl;
				pq.pop();
			}
		}


		//This function will create our Huffman Tree from a priority queue
		void HuffmanTree()
		{
			node* n1, * n2; //The nodes that will be popped each time from the priority queue

			//This loop will continue to pop out two nodes from the priority queue until only one nodes is left
			//in the priority queue
			while (pq.size() != 1)
			{
				n1 = pq.top();
				pq.pop();
				n2 = pq.top();
				pq.pop();
				node* z = new node; //Creation of new node of Huffman tree
				z->left = n1;
				z->right = n2;
				z->f = (n1->f) + (n2->f); //Storing sum of the two popped nodes in Huffman tree node
				z->c = '&'; //Assigning the new node a character that is not used in formal speech
				pq.push(z); //Pushing the node into the priority queue again

			}

			node* root = pq.top(); //Making the last node the root node
			EncodeAndPrintCodes(root, encoded); //Passing the root node and a string that will encode each character of our inputted string
		}

		//This function will recursively search for a character in the string, and will print it's corresponding code.
		//It will do this for all our characters
		void EncodeAndPrintCodes(node* root, std::string en)
		{

			if (root == NULL)
			{

				return;
			}

			if (root->c != '&')
			{
				//cout << root->c << ":" << en;
				StoreinMap(root->c, en);

			}

			EncodeAndPrintCodes(root->left, en + "0");
			EncodeAndPrintCodes(root->right, en + "1");

		}

		//Will convert our code in string to bitstream and then store it in a text file
		void CompressedFile()
		{

			std::ofstream compressed;
			std::string output = "";
			compressed.open("CompressedFile.txt", std::ios::app | std::ios::out);


		}

		void StoreinMap(char ch, std::string code)
		{


			um.emplace(std::pair<char, std::string>(ch, code));

		}

		/*void DisplayEncoded()
		{
			cout << encoded;
		}*/
		void StoreInMap()
		{
			encoded = "";
			for (int i = 0; i < text.size(); i++)
			{
				char f = text[i];
				auto iter = um.begin();
				while (iter != um.end())
				{
					//cout << "[" << iter->first << "," << iter->second << "]\n";

					if (f == iter->first)
					{
						encoded += iter->second;
						break;

					}
					++iter;
				}


			}
			
		}
		void BitStreamConverter()
		{
			std::cout << std::endl;
			std::istringstream in(encoded);
			std::bitset<8> bs;
			while (in >> bs)
				e.push_back(char(bs.to_ulong()));
			std::vector<char>::iterator i = e.begin();
			while (i != e.end())
			{
				std::cout << *i;
				i++;
				//file_write(*i);

			}
			
		}

		//Will save our encoded data in 
		void EncodeInFile()
		{
			std::ofstream MyFile("Compressed.txt");

			for (int i = 0; i < e.size(); i++)
				MyFile << e[i];

			// Close the file
			MyFile.close();
		}
		std::string HuffmanDecoding()
		{
			std::string ans = "";
			node* curr = pq.top();
			std::cout << std::endl;
			for (int i = 0; i < encoded.size(); i++)
			{
				if (encoded[i] == '0')
					curr = curr->left;
				else
					curr = curr->right;

				// reached leaf node
				if (curr->left == NULL && curr->right == NULL)
				{
					ans += curr->c;
					curr = pq.top();
				}
			}
			std::cout << ans << std::endl;
			//file_d(ans);

			DecodedFile(ans);
			return ans;
		}


		//Displays the size of the priority queue
		void DisplaySize()
		{
			std::cout << pq.size();
		}

		void DecodedFile(std::string d)
		{
			std::ofstream decompress;
			decompress.open("Decompressed.txt");
			decompress << d;
		}
};
