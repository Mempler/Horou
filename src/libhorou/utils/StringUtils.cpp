/*
Copyright (c) 2019 Robin A. P.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
*/

#include "StringUtils.h"

namespace Utils {
    bool EndsWith(const std::string& s, const std::string& suffix)
    {
        return s.size() >= suffix.size() &&
               s.substr(s.size() - suffix.size()) == suffix;
    }

    std::vector<std::string> Split(const std::string& str,
                                   const std::string& token,
                                   bool remove_empty_entries) {
        std::vector<std::string> entries;

        for (size_t start = 0, end; start < str.length(); start = end + token.length())
        {
            size_t position = str.find(token, start);
            end = position != std::string::npos ? position : str.length();

            std::string tok = str.substr(start, end - start);
            if (!remove_empty_entries || !tok.empty())
                entries.push_back(tok);
        }

        if (!remove_empty_entries &&
            (str.empty() || EndsWith(str, token)))
            entries.emplace_back("");

        return entries;
    }
}
