#include "service.h"

service::service(repo&r): re(r) {}

void service::add(const Session& s)
{
	re.add(s);
}

std::vector<Session> service::getAll()
{
	return re.getAll();
}

void service::addentites()
{
	Session a{6, 8, "running", 45, "cardio"};
	Session b{4, 5, "yoga", 81, "flexibility"};
	Session c(3,5, "hiit", 12, "higth");
	re.add(a);
	re.add(b);
	re.add(c);
}