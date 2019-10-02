// Gets a command line option by a key passed
// for example: getCmdOption(argc, argv, "-ip=");
// will return the -ip value 

// TODO :: 
// 0. implement fully

//std::string get_cmd_option(int argc, char* argv[], const std::string& option)
//{
//	std::string cmd;
//	for (int i = 0; i < argc; ++i)
//	{
//		std::string arg = argv[i];
//		if (0 == arg.find(option))
//		{
//			size_t found = arg.find_last_of(option);
//			cout << "Debug 1" << endl;
//			cmd = arg.substr(found + 1);
//			cout << "Debug 2" << endl;
//			return cmd;
//		}
//	}
//
//	return cmd;
//}
