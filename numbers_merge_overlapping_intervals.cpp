#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct interval
{
	int start;
	int end;
};

typedef struct interval interval;

bool compare_interval(interval a, interval b)
{
	return (a.start < b.start);
}

void merge_overlapping_intervals(vector<interval>& intervals)
{
	if(intervals.size() <= 0)
		return;

	sort(intervals.begin(), intervals.end(), compare_interval);

	stack<interval> mystack;

	mystack.push(intervals[0]);

	for(int i=1;i<intervals.size();i++)
	{
		interval top = mystack.top();
		if(top.end < intervals[i].start)
		{
			mystack.push(intervals[i]);
		}
		else if(top.end >= intervals[i].start)
		{
			top.end = intervals[i].end;
			mystack.pop();
			mystack.push(top);
		}
	}

	cout << "result :: ";
	while(!mystack.empty())
	{
		cout << " (" << mystack.top().start << "," << mystack.top().end << ")";
		mystack.pop();
	}
	cout << endl;
}

int main()
{
	interval x[] = { {1,3},{7,9},{4,6},{10,13} };

	vector<interval> intervals;

	for(int i=0;i<4;i++)
	{
		intervals.push_back(x[i]);
	}

	merge_overlapping_intervals(intervals);
}
