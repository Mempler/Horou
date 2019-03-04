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

#include "HTTPHandler.h"

void HTTPHandler(http::Request& req, http::Response& res) {

    if (req.GetMethod() == http::Method::POST) {

    } else {
        TextBuffer buff;
        buff.WriteLine("No u");
        res.Write(&buff);
    }

    res.Close();
}
