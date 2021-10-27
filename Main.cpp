long long min(long long a, long long b)
{
    return a < b ? a : b;
}
long long dSequence(long long d, std::vector<int> a)
{
    long long pot = a[0] + d, k3 = 0, kq = 1e18, n = a.size(), l1, l2;
    vector<long long>k1{0}, k2, key; 
    for (int i = 1; i < n; i++){
        long long p = pot - a[i];
        if (p < 0) k1.push_back(p);
        else if (p > 0) 
            k2.push_back(p);
        else 
            k3 += 1;
        pot += d;
    }
    l1 = k1.size();
    l2 = k2.size();
    sort(k1.begin(), k1.end());
    sort(k2.begin(), k2.end());
    int ok = l2 - n / 2;
    if (ok > 0)
        for (int j = max(0, ok - 3); j < min(ok + 3, l2); j++){
            key.push_back(k2[j] + 1); 
            key.push_back(k2[j]);
        }
    else if (ok < 0){
        ok = abs(ok);
        for (int j = max(0, ok - 3); j < min(ok + 3, l1); j++){
            key.push_back(k1[j] + 1); 
            key.push_back(k1[j]);
        }
    }
    else
        return 0;
    for (long long x : key){
        x = a[0] - x;
        long long pile = 0;
        for (int j : a){
            pile += (abs(j - x));
            x += d;
        }
        kq = min(kq, pile);
    }
    return kq;
}
