#include <string>
#include <stack>

//feel free to add other classes/methods if you want
bool DetermineXml(const std::string &input)
{
    std::stack<std::string> tags;
    std::string::size_type curPos = 0;

    while ((curPos = input.find('<', curPos)) != std::string::npos) {
        std::string::size_type endPos = input.find('>', curPos);
        if (endPos != std::string::npos && endPos > curPos) {
            // empty tag treated as invalid
            if (endPos == curPos + 1) {
                return false;
            }
            // opening tag and closing tag are not needed
            curPos += 1;
            endPos -= 1;

            bool isClosingTag = false;
            if (input[curPos] == '/') {
                // mark and move index forward
                isClosingTag = true;
                curPos += 1;
            }
            std::string tag = input.substr(curPos, endPos - curPos + 1);
            if (isClosingTag) {
                if (tags.size() > 0 && tags.top().compare(tag) == 0) {
                    tags.pop();
                }
                else {
                    // not well nested
                    return false;
                }
            }
            else {
                tags.push(tag);
            }
            curPos = endPos + 1;
        }
        else {
            break;
        }
    }
    return tags.size()==0;
}
