 = cache.rbegin(); ii != cache.rend(); ii++) {
        // cout << *ii << endl;
        ss << *ii;
        if (ii != --cache.rend())
            ss << '-';
    }