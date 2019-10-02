#include <iostream>
using namespace std;

class InputValidator
{
	int inputValid = 0;
	string scriptName = "";
	
	void setScriptName(char arr[])
	{
		string raw_name = arr;
		raw_name.substr(raw_name.find_last_of( '\\' ) +1);
		this->scriptName = raw_name;
	}
	
	void showHelp()
	{
		cout << "Usage: " << this->scriptName 
			<< " <inputfile> <output_file>" 
			<< endl;
	}
	
	public:
		int validateInput(int argc, char *argv[])
		{
			this->setScriptName(argv[0]);
			
			// the first arg is the full path to the executable
			// so we are expecting a total of two arguments
			if(2 != argc){
				cout << "Expecting 1 argument - filename to be read." 
			  			<< " Got: " << argc-1 << "!" << endl;
				this->showHelp();
				this->inputValid = 0;
				return 1;
			}
			
			// check that the file exists
			// check if the file can be read
			if(0)
			{
				this->inputValid = 0;
				return 1;
			}
			
			this->inputValid = 1;
		}
		
		int isInputValid()
		{
			return this->inputValid;
		}
	// end public
};

int main(int argc, char *argv[])
{	
	InputValidator validator;
	validator.validateInput(argc, argv);
	
	if(validator.isInputValid())
	{
		// rest of the logic
		return 0;
	}
	return 1;
}
