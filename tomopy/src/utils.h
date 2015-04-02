// Copyright (c) 2015, UChicago Argonne, LLC. All rights reserved.

// Copyright 2015. UChicago Argonne, LLC. This software was produced 
// under U.S. Government contract DE-AC02-06CH11357 for Argonne National 
// Laboratory (ANL), which is operated by UChicago Argonne, LLC for the 
// U.S. Department of Energy. The U.S. Government has rights to use, 
// reproduce, and distribute this software.  NEITHER THE GOVERNMENT NOR 
// UChicago Argonne, LLC MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR 
// ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE.  If software is 
// modified to produce derivative works, such modified software should 
// be clearly marked, so as not to confuse it with the version available 
// from ANL.

// Additionally, redistribution and use in source and binary forms, with 
// or without modification, are permitted provided that the following 
// conditions are met:

//     * Redistributions of source code must retain the above copyright 
//       notice, this list of conditions and the following disclaimer. 

//     * Redistributions in binary form must reproduce the above copyright 
//       notice, this list of conditions and the following disclaimer in 
//       the documentation and/or other materials provided with the 
//       distribution. 

//     * Neither the name of UChicago Argonne, LLC, Argonne National 
//       Laboratory, ANL, the U.S. Government, nor the names of its 
//       contributors may be used to endorse or promote products derived 
//       from this software without specific prior written permission. 

// THIS SOFTWARE IS PROVIDED BY UChicago Argonne, LLC AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL UChicago 
// Argonne, LLC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.

#ifndef _utils_h
#define _utils_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <sys/time.h>
#include <assert.h>
#include <pthread.h>
#include "string.h"


#define _USE_MATH_DEFINES
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327
#endif

#ifdef WIN32
#define DLL __declspec(dllexport)
#else
#define DLL 
#endif


typedef struct {
  int niter;
  float beta;
  float delta;
  float center;
  int nproj;
  int nslice;
  int npixel;
  int ngridx;
  int ngridy;
  int isubset;
  int nsubset;
  bool emission;
} recon_pars;


void art(
        float *data, float *theta, 
        recon_pars *pars, float *model);

void preprocessing(
        int ngridx, int ngridy, 
        int npixel, float center, 
        float *mov, float *gridx, float *gridy);

bool calc_quadrant(
        float theta_p); 

void calc_coords(
        int ngridx, int ngridy,
        float xi, float yi,
        float sin_p, float cos_p,
        float *gridx, float *gridy,
        float *coordx, float *coordy);

void trim_coords(
        int ngridx, int ngridy,
        float *coordx, float *coordy, 
        float *gridx, float* gridy, 
        int *asize, float *ax, float *ay, 
        int *bsize, float *bx, float *by);

void sort_intersections(
        int ind_condition, 
        int asize, float *ax, float *ay, 
        int bsize, float *bx, float *by, 
        int *csize, float *coorx, float *coory);

void calc_dist(
        int ngridx, int ngridy, 
        int csize, float *coorx, float *coory, 
        int *indi, float *dist);

void calc_simdata(
        int p, int s, int c, 
        int ngridx, int ngridy, 
        int nslice, int npixel, 
        int csize, int *indi, float *dist, 
        float *model, float *simdata);

#endif