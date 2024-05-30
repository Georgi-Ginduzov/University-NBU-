package org.nbu.service;

import org.nbu.data.items.Detail;

import java.util.Comparator;

public class DetailsServiceImpl {
    public Comparator<Detail> comparatorByDifficultyLevel() {
        return new Comparator<Detail>() {
            @Override
            public int compare(Detail o1, Detail o2) {
                return o1.getDifficultyLevel().compareTo(o2.getDifficultyLevel());
            }
        };
    }
}
