#include "error_reporter.h"

ErrorReporter::ErrorReporter(string message) :
    errorMessage(message) 
{
}

ErrorReporter::~ErrorReporter() throw() 
{
}
		
const char* ErrorReporter::what() const throw()
{
	return errorMessage.c_str();
}
