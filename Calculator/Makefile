MODULES = calc
EXTENSION = calc
DATA = calc--1.0.sql

PG_CONFIG = /home/praveen-pt7975/Documents/allBuilds/REL_17_4_build/bin/pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs )

override CC = g++
CXXFLAGS = -std=c++17 -O2 -fPIC

include $(PGXS)