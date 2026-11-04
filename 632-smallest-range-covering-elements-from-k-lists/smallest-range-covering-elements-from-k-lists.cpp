
class Solution {
public:
    class Node {
    public:
        int data;
        int row;
        int col;

        Node(int val, int r, int c) {
            data = val;
            row = r;
            col = c;
        }
    };

    class compare {
    public:
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<Node*, vector<Node*>, compare> minheap;

        int k = nums.size();
        int maxi = INT_MIN;

        // Insert first element of every list
        for(int i = 0; i < k; i++) {
            int element = nums[i][0];

            maxi = max(maxi, element);

            minheap.push(new Node(element, i, 0));
        }

        int ansstart = minheap.top()->data;
        int ansend = maxi;

        while(!minheap.empty()) {

            Node* top = minheap.top();
            minheap.pop();

            int mini = top->data;
            int row = top->row;
            int col = top->col;

            // Update smallest range
            if((maxi - mini) < (ansend - ansstart) ||
               ((maxi - mini) == (ansend - ansstart) &&
                mini < ansstart)) {

                ansstart = mini;
                ansend = maxi;
            }

            // Insert next element from the same list
            if(col + 1 < nums[row].size()) {

                int nextElement = nums[row][col + 1];

                maxi = max(maxi, nextElement);

                minheap.push(
                    new Node(nextElement, row, col + 1)
                );
            }
            else {
                delete top;
                break;
            }

            delete top;
        }

        // Free remaining heap nodes
        while(!minheap.empty()) {
            delete minheap.top();
            minheap.pop();
        }

        return {ansstart, ansend};
    }
};