//
// Created by Administrator on 2018/1/25.
//

#ifndef LEETCODE_76_H
#define LEETCODE_76_H

#include <string>
#include <vector>
#include <list>

class Solution {
public:
    std::string minWindow(std::string source, std::string target) {
        std::vector<std::list<std::size_t> > pos_vec(target.size());

        for (std::size_t i = 0; i < source.size(); ++i) {
            char ch = source[i];
            std::size_t pos = target.find(ch);
            if (pos != std::string::npos) {
                pos_vec[pos].push_back(i);
            }
        }

        std::size_t min_pos = std::string::npos;
        std::size_t min_length = std::string::npos;

        bool done = false;
        while (true) {
            std::size_t min = std::string::npos;
            std::size_t max = 0;
            std::list<std::size_t>* min_list = NULL;

            for (std::vector<std::list<std::size_t> >::iterator it = pos_vec.begin(); it != pos_vec.end(); ++it) {
                std::list<std::size_t>& pos_list = *it;
                if (pos_list.empty()) {
                    done = true;
                    break;
                }

                if (pos_list.front() < min) {
                    min = pos_list.front();
                    min_list = &pos_list;
                }

                if (pos_list.front() > max) {
                    max = pos_list.front();
                }
            }

            if (done) {
                break;
            }
            min_list->pop_front();

            std::size_t length = max - min + 1;
            if (length < min_length) {
                min_length = length;
                min_pos = min;
            }
        }

        if (min_pos == std::string::npos) {
            return "";
        }

        return source.substr(min_pos, min_length);
    }
};

#endif //LEETCODE_76_H
