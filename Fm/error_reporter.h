#ifndef ERROR_REPORTER_H
#define ERROR_REPORTER_H

#include <exception>
#include <string>

using std::exception;
using std::string;

class ErrorReporter : public exception
{
    public:
        explicit ErrorReporter(string message);
        virtual ~ErrorReporter() throw();        

	virtual const char* what() const throw();
    protected:
        string errorMessage;
};

#endif // ERROR_REPORTER_H
