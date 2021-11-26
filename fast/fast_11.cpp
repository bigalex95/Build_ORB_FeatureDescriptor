/*This is mechanically generated code*/
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct
{
  int x, y;
  float angle;
} KeyPoint;
typedef unsigned char byte;

int fast11_corner_score(const byte *p, const int pixel[], int bstart)
{
  int bmin = bstart;
  int bmax = 255;
  int b = (bmax + bmin) / 2;

  /*Compute the score using binary search*/
  for (;;)
  {
    int cb = *p + b;
    int c_b = *p - b;

    if (p[pixel[0]] > cb)
      if (p[pixel[1]] > cb)
        if (p[pixel[2]] > cb)
          if (p[pixel[3]] > cb)
            if (p[pixel[4]] > cb)
              if (p[pixel[5]] > cb)
                if (p[pixel[6]] > cb)
                  if (p[pixel[7]] > cb)
                    if (p[pixel[8]] > cb)
                      if (p[pixel[9]] > cb)
                        if (p[pixel[10]] > cb)
                          goto is_a_corner;
                        else if (p[pixel[15]] > cb)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else if (p[pixel[11]] > cb)
                  if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else if (p[pixel[5]] < c_b)
                if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else if (p[pixel[10]] < c_b)
                  if (p[pixel[6]] < c_b)
                    if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                        if (p[pixel[9]] < c_b)
                          if (p[pixel[11]] < c_b)
                            if (p[pixel[12]] < c_b)
                              if (p[pixel[13]] < c_b)
                                if (p[pixel[14]] < c_b)
                                  if (p[pixel[15]] < c_b)
                                    goto is_a_corner;
                                  else
                                    goto is_not_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else if (p[pixel[10]] > cb)
                if (p[pixel[11]] > cb)
                  if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else if (p[pixel[4]] < c_b)
              if (p[pixel[15]] > cb)
                if (p[pixel[9]] > cb)
                  if (p[pixel[10]] > cb)
                    if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else if (p[pixel[9]] < c_b)
                  if (p[pixel[5]] < c_b)
                    if (p[pixel[6]] < c_b)
                      if (p[pixel[7]] < c_b)
                        if (p[pixel[8]] < c_b)
                          if (p[pixel[10]] < c_b)
                            if (p[pixel[11]] < c_b)
                              if (p[pixel[12]] < c_b)
                                if (p[pixel[13]] < c_b)
                                  if (p[pixel[14]] < c_b)
                                    goto is_a_corner;
                                  else
                                    goto is_not_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else if (p[pixel[5]] < c_b)
                if (p[pixel[6]] < c_b)
                  if (p[pixel[7]] < c_b)
                    if (p[pixel[8]] < c_b)
                      if (p[pixel[9]] < c_b)
                        if (p[pixel[10]] < c_b)
                          if (p[pixel[11]] < c_b)
                            if (p[pixel[12]] < c_b)
                              if (p[pixel[13]] < c_b)
                                if (p[pixel[14]] < c_b)
                                  goto is_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else if (p[pixel[9]] > cb)
              if (p[pixel[10]] > cb)
                if (p[pixel[11]] > cb)
                  if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else if (p[pixel[9]] < c_b)
              if (p[pixel[5]] < c_b)
                if (p[pixel[6]] < c_b)
                  if (p[pixel[7]] < c_b)
                    if (p[pixel[8]] < c_b)
                      if (p[pixel[10]] < c_b)
                        if (p[pixel[11]] < c_b)
                          if (p[pixel[12]] < c_b)
                            if (p[pixel[13]] < c_b)
                              if (p[pixel[14]] < c_b)
                                if (p[pixel[15]] < c_b)
                                  goto is_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else if (p[pixel[3]] < c_b)
            if (p[pixel[14]] > cb)
              if (p[pixel[8]] > cb)
                if (p[pixel[9]] > cb)
                  if (p[pixel[10]] > cb)
                    if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          if (p[pixel[15]] > cb)
                            goto is_a_corner;
                          else if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                              if (p[pixel[6]] > cb)
                                if (p[pixel[7]] > cb)
                                  goto is_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else if (p[pixel[8]] < c_b)
                if (p[pixel[4]] < c_b)
                  if (p[pixel[5]] < c_b)
                    if (p[pixel[6]] < c_b)
                      if (p[pixel[7]] < c_b)
                        if (p[pixel[9]] < c_b)
                          if (p[pixel[10]] < c_b)
                            if (p[pixel[11]] < c_b)
                              if (p[pixel[12]] < c_b)
                                if (p[pixel[13]] < c_b)
                                  goto is_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else if (p[pixel[14]] < c_b)
              if (p[pixel[5]] < c_b)
                if (p[pixel[6]] < c_b)
                  if (p[pixel[7]] < c_b)
                    if (p[pixel[8]] < c_b)
                      if (p[pixel[9]] < c_b)
                        if (p[pixel[10]] < c_b)
                          if (p[pixel[11]] < c_b)
                            if (p[pixel[12]] < c_b)
                              if (p[pixel[13]] < c_b)
                                if (p[pixel[4]] < c_b)
                                  goto is_a_corner;
                                else if (p[pixel[15]] < c_b)
                                  goto is_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else if (p[pixel[4]] < c_b)
              if (p[pixel[5]] < c_b)
                if (p[pixel[6]] < c_b)
                  if (p[pixel[7]] < c_b)
                    if (p[pixel[8]] < c_b)
                      if (p[pixel[9]] < c_b)
                        if (p[pixel[10]] < c_b)
                          if (p[pixel[11]] < c_b)
                            if (p[pixel[12]] < c_b)
                              if (p[pixel[13]] < c_b)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else if (p[pixel[8]] > cb)
            if (p[pixel[9]] > cb)
              if (p[pixel[10]] > cb)
                if (p[pixel[11]] > cb)
                  if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                          goto is_a_corner;
                        else if (p[pixel[4]] > cb)
                          if (p[pixel[5]] > cb)
                            if (p[pixel[6]] > cb)
                              if (p[pixel[7]] > cb)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else if (p[pixel[8]] < c_b)
            if (p[pixel[5]] < c_b)
              if (p[pixel[6]] < c_b)
                if (p[pixel[7]] < c_b)
                  if (p[pixel[9]] < c_b)
                    if (p[pixel[10]] < c_b)
                      if (p[pixel[11]] < c_b)
                        if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                            if (p[pixel[14]] < c_b)
                              if (p[pixel[4]] < c_b)
                                goto is_a_corner;
                              else if (p[pixel[15]] < c_b)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else if (p[pixel[2]] < c_b)
          if (p[pixel[7]] > cb)
            if (p[pixel[8]] > cb)
              if (p[pixel[9]] > cb)
                if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                            goto is_a_corner;
                          else if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                              if (p[pixel[6]] > cb)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else if (p[pixel[3]] > cb)
                          if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                              if (p[pixel[6]] > cb)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else if (p[pixel[7]] < c_b)
            if (p[pixel[5]] < c_b)
              if (p[pixel[6]] < c_b)
                if (p[pixel[8]] < c_b)
                  if (p[pixel[9]] < c_b)
                    if (p[pixel[10]] < c_b)
                      if (p[pixel[11]] < c_b)
                        if (p[pixel[12]] < c_b)
                          if (p[pixel[4]] < c_b)
                            if (p[pixel[3]] < c_b)
                              goto is_a_corner;
                            else if (p[pixel[13]] < c_b)
                              if (p[pixel[14]] < c_b)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else if (p[pixel[13]] < c_b)
                            if (p[pixel[14]] < c_b)
                              if (p[pixel[15]] < c_b)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else if (p[pixel[7]] > cb)
          if (p[pixel[8]] > cb)
            if (p[pixel[9]] > cb)
              if (p[pixel[10]] > cb)
                if (p[pixel[11]] > cb)
                  if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                          goto is_a_corner;
                        else if (p[pixel[4]] > cb)
                          if (p[pixel[5]] > cb)
                            if (p[pixel[6]] > cb)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[3]] > cb)
                        if (p[pixel[4]] > cb)
                          if (p[pixel[5]] > cb)
                            if (p[pixel[6]] > cb)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else if (p[pixel[7]] < c_b)
          if (p[pixel[5]] < c_b)
            if (p[pixel[6]] < c_b)
              if (p[pixel[8]] < c_b)
                if (p[pixel[9]] < c_b)
                  if (p[pixel[10]] < c_b)
                    if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          if (p[pixel[4]] < c_b)
                            if (p[pixel[3]] < c_b)
                              goto is_a_corner;
                            else if (p[pixel[14]] < c_b)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else if (p[pixel[14]] < c_b)
                            if (p[pixel[15]] < c_b)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else
          goto is_not_a_corner;
      else if (p[pixel[1]] < c_b)
        if (p[pixel[6]] > cb)
          if (p[pixel[7]] > cb)
            if (p[pixel[8]] > cb)
              if (p[pixel[9]] > cb)
                if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                            goto is_a_corner;
                          else if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else if (p[pixel[3]] > cb)
                          if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[2]] > cb)
                        if (p[pixel[3]] > cb)
                          if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else if (p[pixel[6]] < c_b)
          if (p[pixel[5]] < c_b)
            if (p[pixel[7]] < c_b)
              if (p[pixel[8]] < c_b)
                if (p[pixel[9]] < c_b)
                  if (p[pixel[10]] < c_b)
                    if (p[pixel[11]] < c_b)
                      if (p[pixel[4]] < c_b)
                        if (p[pixel[3]] < c_b)
                          if (p[pixel[2]] < c_b)
                            goto is_a_corner;
                          else if (p[pixel[12]] < c_b)
                            if (p[pixel[13]] < c_b)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                            if (p[pixel[14]] < c_b)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                            if (p[pixel[15]] < c_b)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else
          goto is_not_a_corner;
      else if (p[pixel[6]] > cb)
        if (p[pixel[7]] > cb)
          if (p[pixel[8]] > cb)
            if (p[pixel[9]] > cb)
              if (p[pixel[10]] > cb)
                if (p[pixel[11]] > cb)
                  if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                          goto is_a_corner;
                        else if (p[pixel[4]] > cb)
                          if (p[pixel[5]] > cb)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[3]] > cb)
                        if (p[pixel[4]] > cb)
                          if (p[pixel[5]] > cb)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else if (p[pixel[2]] > cb)
                      if (p[pixel[3]] > cb)
                        if (p[pixel[4]] > cb)
                          if (p[pixel[5]] > cb)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else
          goto is_not_a_corner;
      else if (p[pixel[6]] < c_b)
        if (p[pixel[5]] < c_b)
          if (p[pixel[7]] < c_b)
            if (p[pixel[8]] < c_b)
              if (p[pixel[9]] < c_b)
                if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[4]] < c_b)
                        if (p[pixel[3]] < c_b)
                          if (p[pixel[2]] < c_b)
                            goto is_a_corner;
                          else if (p[pixel[13]] < c_b)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else
          goto is_not_a_corner;
      else
        goto is_not_a_corner;
    else if (p[pixel[0]] < c_b)
      if (p[pixel[1]] > cb)
        if (p[pixel[6]] > cb)
          if (p[pixel[5]] > cb)
            if (p[pixel[7]] > cb)
              if (p[pixel[8]] > cb)
                if (p[pixel[9]] > cb)
                  if (p[pixel[10]] > cb)
                    if (p[pixel[11]] > cb)
                      if (p[pixel[4]] > cb)
                        if (p[pixel[3]] > cb)
                          if (p[pixel[2]] > cb)
                            goto is_a_corner;
                          else if (p[pixel[12]] > cb)
                            if (p[pixel[13]] > cb)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                            if (p[pixel[14]] > cb)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                            if (p[pixel[15]] > cb)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else if (p[pixel[6]] < c_b)
          if (p[pixel[7]] < c_b)
            if (p[pixel[8]] < c_b)
              if (p[pixel[9]] < c_b)
                if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                            goto is_a_corner;
                          else if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else if (p[pixel[3]] < c_b)
                          if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[2]] < c_b)
                        if (p[pixel[3]] < c_b)
                          if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else
          goto is_not_a_corner;
      else if (p[pixel[1]] < c_b)
        if (p[pixel[2]] > cb)
          if (p[pixel[7]] > cb)
            if (p[pixel[5]] > cb)
              if (p[pixel[6]] > cb)
                if (p[pixel[8]] > cb)
                  if (p[pixel[9]] > cb)
                    if (p[pixel[10]] > cb)
                      if (p[pixel[11]] > cb)
                        if (p[pixel[12]] > cb)
                          if (p[pixel[4]] > cb)
                            if (p[pixel[3]] > cb)
                              goto is_a_corner;
                            else if (p[pixel[13]] > cb)
                              if (p[pixel[14]] > cb)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else if (p[pixel[13]] > cb)
                            if (p[pixel[14]] > cb)
                              if (p[pixel[15]] > cb)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else if (p[pixel[7]] < c_b)
            if (p[pixel[8]] < c_b)
              if (p[pixel[9]] < c_b)
                if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                            goto is_a_corner;
                          else if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                              if (p[pixel[6]] < c_b)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else if (p[pixel[3]] < c_b)
                          if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                              if (p[pixel[6]] < c_b)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else if (p[pixel[2]] < c_b)
          if (p[pixel[3]] > cb)
            if (p[pixel[14]] > cb)
              if (p[pixel[5]] > cb)
                if (p[pixel[6]] > cb)
                  if (p[pixel[7]] > cb)
                    if (p[pixel[8]] > cb)
                      if (p[pixel[9]] > cb)
                        if (p[pixel[10]] > cb)
                          if (p[pixel[11]] > cb)
                            if (p[pixel[12]] > cb)
                              if (p[pixel[13]] > cb)
                                if (p[pixel[4]] > cb)
                                  goto is_a_corner;
                                else if (p[pixel[15]] > cb)
                                  goto is_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else if (p[pixel[14]] < c_b)
              if (p[pixel[8]] > cb)
                if (p[pixel[4]] > cb)
                  if (p[pixel[5]] > cb)
                    if (p[pixel[6]] > cb)
                      if (p[pixel[7]] > cb)
                        if (p[pixel[9]] > cb)
                          if (p[pixel[10]] > cb)
                            if (p[pixel[11]] > cb)
                              if (p[pixel[12]] > cb)
                                if (p[pixel[13]] > cb)
                                  goto is_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else if (p[pixel[8]] < c_b)
                if (p[pixel[9]] < c_b)
                  if (p[pixel[10]] < c_b)
                    if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          if (p[pixel[15]] < c_b)
                            goto is_a_corner;
                          else if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                              if (p[pixel[6]] < c_b)
                                if (p[pixel[7]] < c_b)
                                  goto is_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else if (p[pixel[4]] > cb)
              if (p[pixel[5]] > cb)
                if (p[pixel[6]] > cb)
                  if (p[pixel[7]] > cb)
                    if (p[pixel[8]] > cb)
                      if (p[pixel[9]] > cb)
                        if (p[pixel[10]] > cb)
                          if (p[pixel[11]] > cb)
                            if (p[pixel[12]] > cb)
                              if (p[pixel[13]] > cb)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else if (p[pixel[3]] < c_b)
            if (p[pixel[4]] > cb)
              if (p[pixel[15]] < c_b)
                if (p[pixel[9]] > cb)
                  if (p[pixel[5]] > cb)
                    if (p[pixel[6]] > cb)
                      if (p[pixel[7]] > cb)
                        if (p[pixel[8]] > cb)
                          if (p[pixel[10]] > cb)
                            if (p[pixel[11]] > cb)
                              if (p[pixel[12]] > cb)
                                if (p[pixel[13]] > cb)
                                  if (p[pixel[14]] > cb)
                                    goto is_a_corner;
                                  else
                                    goto is_not_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else if (p[pixel[9]] < c_b)
                  if (p[pixel[10]] < c_b)
                    if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else if (p[pixel[5]] > cb)
                if (p[pixel[6]] > cb)
                  if (p[pixel[7]] > cb)
                    if (p[pixel[8]] > cb)
                      if (p[pixel[9]] > cb)
                        if (p[pixel[10]] > cb)
                          if (p[pixel[11]] > cb)
                            if (p[pixel[12]] > cb)
                              if (p[pixel[13]] > cb)
                                if (p[pixel[14]] > cb)
                                  goto is_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else if (p[pixel[4]] < c_b)
              if (p[pixel[5]] > cb)
                if (p[pixel[10]] > cb)
                  if (p[pixel[6]] > cb)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                        if (p[pixel[9]] > cb)
                          if (p[pixel[11]] > cb)
                            if (p[pixel[12]] > cb)
                              if (p[pixel[13]] > cb)
                                if (p[pixel[14]] > cb)
                                  if (p[pixel[15]] > cb)
                                    goto is_a_corner;
                                  else
                                    goto is_not_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else if (p[pixel[5]] < c_b)
                if (p[pixel[6]] < c_b)
                  if (p[pixel[7]] < c_b)
                    if (p[pixel[8]] < c_b)
                      if (p[pixel[9]] < c_b)
                        if (p[pixel[10]] < c_b)
                          goto is_a_corner;
                        else if (p[pixel[15]] < c_b)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else if (p[pixel[11]] < c_b)
                  if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else if (p[pixel[10]] < c_b)
                if (p[pixel[11]] < c_b)
                  if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else if (p[pixel[9]] > cb)
              if (p[pixel[5]] > cb)
                if (p[pixel[6]] > cb)
                  if (p[pixel[7]] > cb)
                    if (p[pixel[8]] > cb)
                      if (p[pixel[10]] > cb)
                        if (p[pixel[11]] > cb)
                          if (p[pixel[12]] > cb)
                            if (p[pixel[13]] > cb)
                              if (p[pixel[14]] > cb)
                                if (p[pixel[15]] > cb)
                                  goto is_a_corner;
                                else
                                  goto is_not_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else if (p[pixel[9]] < c_b)
              if (p[pixel[10]] < c_b)
                if (p[pixel[11]] < c_b)
                  if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else if (p[pixel[8]] > cb)
            if (p[pixel[5]] > cb)
              if (p[pixel[6]] > cb)
                if (p[pixel[7]] > cb)
                  if (p[pixel[9]] > cb)
                    if (p[pixel[10]] > cb)
                      if (p[pixel[11]] > cb)
                        if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                            if (p[pixel[14]] > cb)
                              if (p[pixel[4]] > cb)
                                goto is_a_corner;
                              else if (p[pixel[15]] > cb)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else if (p[pixel[8]] < c_b)
            if (p[pixel[9]] < c_b)
              if (p[pixel[10]] < c_b)
                if (p[pixel[11]] < c_b)
                  if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                          goto is_a_corner;
                        else if (p[pixel[4]] < c_b)
                          if (p[pixel[5]] < c_b)
                            if (p[pixel[6]] < c_b)
                              if (p[pixel[7]] < c_b)
                                goto is_a_corner;
                              else
                                goto is_not_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else if (p[pixel[7]] > cb)
          if (p[pixel[5]] > cb)
            if (p[pixel[6]] > cb)
              if (p[pixel[8]] > cb)
                if (p[pixel[9]] > cb)
                  if (p[pixel[10]] > cb)
                    if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          if (p[pixel[4]] > cb)
                            if (p[pixel[3]] > cb)
                              goto is_a_corner;
                            else if (p[pixel[14]] > cb)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else if (p[pixel[14]] > cb)
                            if (p[pixel[15]] > cb)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else if (p[pixel[7]] < c_b)
          if (p[pixel[8]] < c_b)
            if (p[pixel[9]] < c_b)
              if (p[pixel[10]] < c_b)
                if (p[pixel[11]] < c_b)
                  if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                          goto is_a_corner;
                        else if (p[pixel[4]] < c_b)
                          if (p[pixel[5]] < c_b)
                            if (p[pixel[6]] < c_b)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[3]] < c_b)
                        if (p[pixel[4]] < c_b)
                          if (p[pixel[5]] < c_b)
                            if (p[pixel[6]] < c_b)
                              goto is_a_corner;
                            else
                              goto is_not_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else
          goto is_not_a_corner;
      else if (p[pixel[6]] > cb)
        if (p[pixel[5]] > cb)
          if (p[pixel[7]] > cb)
            if (p[pixel[8]] > cb)
              if (p[pixel[9]] > cb)
                if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[4]] > cb)
                        if (p[pixel[3]] > cb)
                          if (p[pixel[2]] > cb)
                            goto is_a_corner;
                          else if (p[pixel[13]] > cb)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else
          goto is_not_a_corner;
      else if (p[pixel[6]] < c_b)
        if (p[pixel[7]] < c_b)
          if (p[pixel[8]] < c_b)
            if (p[pixel[9]] < c_b)
              if (p[pixel[10]] < c_b)
                if (p[pixel[11]] < c_b)
                  if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                          goto is_a_corner;
                        else if (p[pixel[4]] < c_b)
                          if (p[pixel[5]] < c_b)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[3]] < c_b)
                        if (p[pixel[4]] < c_b)
                          if (p[pixel[5]] < c_b)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else if (p[pixel[2]] < c_b)
                      if (p[pixel[3]] < c_b)
                        if (p[pixel[4]] < c_b)
                          if (p[pixel[5]] < c_b)
                            goto is_a_corner;
                          else
                            goto is_not_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else
          goto is_not_a_corner;
      else
        goto is_not_a_corner;
    else if (p[pixel[5]] > cb)
      if (p[pixel[6]] > cb)
        if (p[pixel[7]] > cb)
          if (p[pixel[8]] > cb)
            if (p[pixel[9]] > cb)
              if (p[pixel[10]] > cb)
                if (p[pixel[11]] > cb)
                  if (p[pixel[4]] > cb)
                    if (p[pixel[3]] > cb)
                      if (p[pixel[2]] > cb)
                        if (p[pixel[1]] > cb)
                          goto is_a_corner;
                        else if (p[pixel[12]] > cb)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else if (p[pixel[12]] > cb)
                    if (p[pixel[13]] > cb)
                      if (p[pixel[14]] > cb)
                        if (p[pixel[15]] > cb)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else
          goto is_not_a_corner;
      else
        goto is_not_a_corner;
    else if (p[pixel[5]] < c_b)
      if (p[pixel[6]] < c_b)
        if (p[pixel[7]] < c_b)
          if (p[pixel[8]] < c_b)
            if (p[pixel[9]] < c_b)
              if (p[pixel[10]] < c_b)
                if (p[pixel[11]] < c_b)
                  if (p[pixel[4]] < c_b)
                    if (p[pixel[3]] < c_b)
                      if (p[pixel[2]] < c_b)
                        if (p[pixel[1]] < c_b)
                          goto is_a_corner;
                        else if (p[pixel[12]] < c_b)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else if (p[pixel[12]] < c_b)
                    if (p[pixel[13]] < c_b)
                      if (p[pixel[14]] < c_b)
                        if (p[pixel[15]] < c_b)
                          goto is_a_corner;
                        else
                          goto is_not_a_corner;
                      else
                        goto is_not_a_corner;
                    else
                      goto is_not_a_corner;
                  else
                    goto is_not_a_corner;
                else
                  goto is_not_a_corner;
              else
                goto is_not_a_corner;
            else
              goto is_not_a_corner;
          else
            goto is_not_a_corner;
        else
          goto is_not_a_corner;
      else
        goto is_not_a_corner;
    else
      goto is_not_a_corner;

  is_a_corner:
    bmin = b;
    goto end_if;

  is_not_a_corner:
    bmax = b;
    goto end_if;

  end_if:

    if (bmin == bmax - 1 || bmin == bmax)
      return bmin;
    b = (bmin + bmax) / 2;
  }
}

static void make_offsets(int pixel[], int row_bytes_per_row)
{
  pixel[0] = 0 + row_bytes_per_row * 3;
  pixel[1] = 1 + row_bytes_per_row * 3;
  pixel[2] = 2 + row_bytes_per_row * 2;
  pixel[3] = 3 + row_bytes_per_row * 1;
  pixel[4] = 3 + row_bytes_per_row * 0;
  pixel[5] = 3 + row_bytes_per_row * -1;
  pixel[6] = 2 + row_bytes_per_row * -2;
  pixel[7] = 1 + row_bytes_per_row * -3;
  pixel[8] = 0 + row_bytes_per_row * -3;
  pixel[9] = -1 + row_bytes_per_row * -3;
  pixel[10] = -2 + row_bytes_per_row * -2;
  pixel[11] = -3 + row_bytes_per_row * -1;
  pixel[12] = -3 + row_bytes_per_row * 0;
  pixel[13] = -3 + row_bytes_per_row * 1;
  pixel[14] = -2 + row_bytes_per_row * 2;
  pixel[15] = -1 + row_bytes_per_row * 3;
}

int *fast11_score(const byte *i, int bytes_per_row, vector<KeyPoint> corners, int num_corners, int b)
{
  int *scores = (int *)malloc(sizeof(int) * num_corners);
  int n;

  int pixel[16];
  make_offsets(pixel, bytes_per_row);

  for (n = 0; n < num_corners; n++)
    scores[n] = fast11_corner_score(i + corners[n].y * bytes_per_row + corners[n].x, pixel, b);

  return scores;
}

vector<KeyPoint> fast11_detect(const byte *im, int cols, int rows, int bytes_per_row, int b, int *ret_num_corners)
{
  int num_corners = 0;
  vector<KeyPoint> ret_corners;
  KeyPoint posxy;
  int pixel[16];
  int x, y;

  make_offsets(pixel, bytes_per_row);

  for (y = 3; y < rows - 3; y++)
    for (x = 3; x < cols - 3; x++)
    {
      const byte *p = im + y * bytes_per_row + x;

      int cb = *p + b;
      int c_b = *p - b;
      if (p[pixel[0]] > cb)
        if (p[pixel[1]] > cb)
          if (p[pixel[2]] > cb)
            if (p[pixel[3]] > cb)
              if (p[pixel[4]] > cb)
                if (p[pixel[5]] > cb)
                  if (p[pixel[6]] > cb)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                        if (p[pixel[9]] > cb)
                          if (p[pixel[10]] > cb)
                          {
                          }
                          else if (p[pixel[15]] > cb)
                          {
                          }
                          else
                            continue;
                        else if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[5]] < c_b)
                  if (p[pixel[10]] > cb)
                    if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                            if (p[pixel[15]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[10]] < c_b)
                    if (p[pixel[6]] < c_b)
                      if (p[pixel[7]] < c_b)
                        if (p[pixel[8]] < c_b)
                          if (p[pixel[9]] < c_b)
                            if (p[pixel[11]] < c_b)
                              if (p[pixel[12]] < c_b)
                                if (p[pixel[13]] < c_b)
                                  if (p[pixel[14]] < c_b)
                                    if (p[pixel[15]] < c_b)
                                    {
                                    }
                                    else
                                      continue;
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[4]] < c_b)
                if (p[pixel[15]] > cb)
                  if (p[pixel[9]] > cb)
                    if (p[pixel[10]] > cb)
                      if (p[pixel[11]] > cb)
                        if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                            if (p[pixel[14]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[9]] < c_b)
                    if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[8]] < c_b)
                            if (p[pixel[10]] < c_b)
                              if (p[pixel[11]] < c_b)
                                if (p[pixel[12]] < c_b)
                                  if (p[pixel[13]] < c_b)
                                    if (p[pixel[14]] < c_b)
                                    {
                                    }
                                    else
                                      continue;
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[5]] < c_b)
                  if (p[pixel[6]] < c_b)
                    if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                        if (p[pixel[9]] < c_b)
                          if (p[pixel[10]] < c_b)
                            if (p[pixel[11]] < c_b)
                              if (p[pixel[12]] < c_b)
                                if (p[pixel[13]] < c_b)
                                  if (p[pixel[14]] < c_b)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[9]] > cb)
                if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[9]] < c_b)
                if (p[pixel[5]] < c_b)
                  if (p[pixel[6]] < c_b)
                    if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                        if (p[pixel[10]] < c_b)
                          if (p[pixel[11]] < c_b)
                            if (p[pixel[12]] < c_b)
                              if (p[pixel[13]] < c_b)
                                if (p[pixel[14]] < c_b)
                                  if (p[pixel[15]] < c_b)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[3]] < c_b)
              if (p[pixel[14]] > cb)
                if (p[pixel[8]] > cb)
                  if (p[pixel[9]] > cb)
                    if (p[pixel[10]] > cb)
                      if (p[pixel[11]] > cb)
                        if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                            if (p[pixel[15]] > cb)
                            {
                            }
                            else if (p[pixel[4]] > cb)
                              if (p[pixel[5]] > cb)
                                if (p[pixel[6]] > cb)
                                  if (p[pixel[7]] > cb)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[8]] < c_b)
                  if (p[pixel[4]] < c_b)
                    if (p[pixel[5]] < c_b)
                      if (p[pixel[6]] < c_b)
                        if (p[pixel[7]] < c_b)
                          if (p[pixel[9]] < c_b)
                            if (p[pixel[10]] < c_b)
                              if (p[pixel[11]] < c_b)
                                if (p[pixel[12]] < c_b)
                                  if (p[pixel[13]] < c_b)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[14]] < c_b)
                if (p[pixel[5]] < c_b)
                  if (p[pixel[6]] < c_b)
                    if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                        if (p[pixel[9]] < c_b)
                          if (p[pixel[10]] < c_b)
                            if (p[pixel[11]] < c_b)
                              if (p[pixel[12]] < c_b)
                                if (p[pixel[13]] < c_b)
                                  if (p[pixel[4]] < c_b)
                                  {
                                  }
                                  else if (p[pixel[15]] < c_b)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[4]] < c_b)
                if (p[pixel[5]] < c_b)
                  if (p[pixel[6]] < c_b)
                    if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                        if (p[pixel[9]] < c_b)
                          if (p[pixel[10]] < c_b)
                            if (p[pixel[11]] < c_b)
                              if (p[pixel[12]] < c_b)
                                if (p[pixel[13]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[8]] > cb)
              if (p[pixel[9]] > cb)
                if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                              if (p[pixel[6]] > cb)
                                if (p[pixel[7]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[8]] < c_b)
              if (p[pixel[5]] < c_b)
                if (p[pixel[6]] < c_b)
                  if (p[pixel[7]] < c_b)
                    if (p[pixel[9]] < c_b)
                      if (p[pixel[10]] < c_b)
                        if (p[pixel[11]] < c_b)
                          if (p[pixel[12]] < c_b)
                            if (p[pixel[13]] < c_b)
                              if (p[pixel[14]] < c_b)
                                if (p[pixel[4]] < c_b)
                                {
                                }
                                else if (p[pixel[15]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[2]] < c_b)
            if (p[pixel[7]] > cb)
              if (p[pixel[8]] > cb)
                if (p[pixel[9]] > cb)
                  if (p[pixel[10]] > cb)
                    if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                            if (p[pixel[15]] > cb)
                            {
                            }
                            else if (p[pixel[4]] > cb)
                              if (p[pixel[5]] > cb)
                                if (p[pixel[6]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else if (p[pixel[3]] > cb)
                            if (p[pixel[4]] > cb)
                              if (p[pixel[5]] > cb)
                                if (p[pixel[6]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[7]] < c_b)
              if (p[pixel[5]] < c_b)
                if (p[pixel[6]] < c_b)
                  if (p[pixel[8]] < c_b)
                    if (p[pixel[9]] < c_b)
                      if (p[pixel[10]] < c_b)
                        if (p[pixel[11]] < c_b)
                          if (p[pixel[12]] < c_b)
                            if (p[pixel[4]] < c_b)
                              if (p[pixel[3]] < c_b)
                              {
                              }
                              else if (p[pixel[13]] < c_b)
                                if (p[pixel[14]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else if (p[pixel[13]] < c_b)
                              if (p[pixel[14]] < c_b)
                                if (p[pixel[15]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[7]] > cb)
            if (p[pixel[8]] > cb)
              if (p[pixel[9]] > cb)
                if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                              if (p[pixel[6]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[3]] > cb)
                          if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                              if (p[pixel[6]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[7]] < c_b)
            if (p[pixel[5]] < c_b)
              if (p[pixel[6]] < c_b)
                if (p[pixel[8]] < c_b)
                  if (p[pixel[9]] < c_b)
                    if (p[pixel[10]] < c_b)
                      if (p[pixel[11]] < c_b)
                        if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                            if (p[pixel[4]] < c_b)
                              if (p[pixel[3]] < c_b)
                              {
                              }
                              else if (p[pixel[14]] < c_b)
                              {
                              }
                              else
                                continue;
                            else if (p[pixel[14]] < c_b)
                              if (p[pixel[15]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[1]] < c_b)
          if (p[pixel[6]] > cb)
            if (p[pixel[7]] > cb)
              if (p[pixel[8]] > cb)
                if (p[pixel[9]] > cb)
                  if (p[pixel[10]] > cb)
                    if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                            if (p[pixel[15]] > cb)
                            {
                            }
                            else if (p[pixel[4]] > cb)
                              if (p[pixel[5]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else if (p[pixel[3]] > cb)
                            if (p[pixel[4]] > cb)
                              if (p[pixel[5]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[2]] > cb)
                          if (p[pixel[3]] > cb)
                            if (p[pixel[4]] > cb)
                              if (p[pixel[5]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[6]] < c_b)
            if (p[pixel[5]] < c_b)
              if (p[pixel[7]] < c_b)
                if (p[pixel[8]] < c_b)
                  if (p[pixel[9]] < c_b)
                    if (p[pixel[10]] < c_b)
                      if (p[pixel[11]] < c_b)
                        if (p[pixel[4]] < c_b)
                          if (p[pixel[3]] < c_b)
                            if (p[pixel[2]] < c_b)
                            {
                            }
                            else if (p[pixel[12]] < c_b)
                              if (p[pixel[13]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else if (p[pixel[12]] < c_b)
                            if (p[pixel[13]] < c_b)
                              if (p[pixel[14]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                            if (p[pixel[14]] < c_b)
                              if (p[pixel[15]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[6]] > cb)
          if (p[pixel[7]] > cb)
            if (p[pixel[8]] > cb)
              if (p[pixel[9]] > cb)
                if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[3]] > cb)
                          if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[2]] > cb)
                        if (p[pixel[3]] > cb)
                          if (p[pixel[4]] > cb)
                            if (p[pixel[5]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[6]] < c_b)
          if (p[pixel[5]] < c_b)
            if (p[pixel[7]] < c_b)
              if (p[pixel[8]] < c_b)
                if (p[pixel[9]] < c_b)
                  if (p[pixel[10]] < c_b)
                    if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                        if (p[pixel[4]] < c_b)
                          if (p[pixel[3]] < c_b)
                            if (p[pixel[2]] < c_b)
                            {
                            }
                            else if (p[pixel[13]] < c_b)
                            {
                            }
                            else
                              continue;
                          else if (p[pixel[13]] < c_b)
                            if (p[pixel[14]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                            if (p[pixel[15]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else
          continue;
      else if (p[pixel[0]] < c_b)
        if (p[pixel[1]] > cb)
          if (p[pixel[6]] > cb)
            if (p[pixel[5]] > cb)
              if (p[pixel[7]] > cb)
                if (p[pixel[8]] > cb)
                  if (p[pixel[9]] > cb)
                    if (p[pixel[10]] > cb)
                      if (p[pixel[11]] > cb)
                        if (p[pixel[4]] > cb)
                          if (p[pixel[3]] > cb)
                            if (p[pixel[2]] > cb)
                            {
                            }
                            else if (p[pixel[12]] > cb)
                              if (p[pixel[13]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else if (p[pixel[12]] > cb)
                            if (p[pixel[13]] > cb)
                              if (p[pixel[14]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                            if (p[pixel[14]] > cb)
                              if (p[pixel[15]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[6]] < c_b)
            if (p[pixel[7]] < c_b)
              if (p[pixel[8]] < c_b)
                if (p[pixel[9]] < c_b)
                  if (p[pixel[10]] < c_b)
                    if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                            if (p[pixel[15]] < c_b)
                            {
                            }
                            else if (p[pixel[4]] < c_b)
                              if (p[pixel[5]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else if (p[pixel[3]] < c_b)
                            if (p[pixel[4]] < c_b)
                              if (p[pixel[5]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[2]] < c_b)
                          if (p[pixel[3]] < c_b)
                            if (p[pixel[4]] < c_b)
                              if (p[pixel[5]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[1]] < c_b)
          if (p[pixel[2]] > cb)
            if (p[pixel[7]] > cb)
              if (p[pixel[5]] > cb)
                if (p[pixel[6]] > cb)
                  if (p[pixel[8]] > cb)
                    if (p[pixel[9]] > cb)
                      if (p[pixel[10]] > cb)
                        if (p[pixel[11]] > cb)
                          if (p[pixel[12]] > cb)
                            if (p[pixel[4]] > cb)
                              if (p[pixel[3]] > cb)
                              {
                              }
                              else if (p[pixel[13]] > cb)
                                if (p[pixel[14]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else if (p[pixel[13]] > cb)
                              if (p[pixel[14]] > cb)
                                if (p[pixel[15]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[7]] < c_b)
              if (p[pixel[8]] < c_b)
                if (p[pixel[9]] < c_b)
                  if (p[pixel[10]] < c_b)
                    if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                            if (p[pixel[15]] < c_b)
                            {
                            }
                            else if (p[pixel[4]] < c_b)
                              if (p[pixel[5]] < c_b)
                                if (p[pixel[6]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else if (p[pixel[3]] < c_b)
                            if (p[pixel[4]] < c_b)
                              if (p[pixel[5]] < c_b)
                                if (p[pixel[6]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[2]] < c_b)
            if (p[pixel[3]] > cb)
              if (p[pixel[14]] > cb)
                if (p[pixel[5]] > cb)
                  if (p[pixel[6]] > cb)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                        if (p[pixel[9]] > cb)
                          if (p[pixel[10]] > cb)
                            if (p[pixel[11]] > cb)
                              if (p[pixel[12]] > cb)
                                if (p[pixel[13]] > cb)
                                  if (p[pixel[4]] > cb)
                                  {
                                  }
                                  else if (p[pixel[15]] > cb)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[14]] < c_b)
                if (p[pixel[8]] > cb)
                  if (p[pixel[4]] > cb)
                    if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[9]] > cb)
                            if (p[pixel[10]] > cb)
                              if (p[pixel[11]] > cb)
                                if (p[pixel[12]] > cb)
                                  if (p[pixel[13]] > cb)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[8]] < c_b)
                  if (p[pixel[9]] < c_b)
                    if (p[pixel[10]] < c_b)
                      if (p[pixel[11]] < c_b)
                        if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                            if (p[pixel[15]] < c_b)
                            {
                            }
                            else if (p[pixel[4]] < c_b)
                              if (p[pixel[5]] < c_b)
                                if (p[pixel[6]] < c_b)
                                  if (p[pixel[7]] < c_b)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[4]] > cb)
                if (p[pixel[5]] > cb)
                  if (p[pixel[6]] > cb)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                        if (p[pixel[9]] > cb)
                          if (p[pixel[10]] > cb)
                            if (p[pixel[11]] > cb)
                              if (p[pixel[12]] > cb)
                                if (p[pixel[13]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[3]] < c_b)
              if (p[pixel[4]] > cb)
                if (p[pixel[15]] < c_b)
                  if (p[pixel[9]] > cb)
                    if (p[pixel[5]] > cb)
                      if (p[pixel[6]] > cb)
                        if (p[pixel[7]] > cb)
                          if (p[pixel[8]] > cb)
                            if (p[pixel[10]] > cb)
                              if (p[pixel[11]] > cb)
                                if (p[pixel[12]] > cb)
                                  if (p[pixel[13]] > cb)
                                    if (p[pixel[14]] > cb)
                                    {
                                    }
                                    else
                                      continue;
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[9]] < c_b)
                    if (p[pixel[10]] < c_b)
                      if (p[pixel[11]] < c_b)
                        if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                            if (p[pixel[14]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[5]] > cb)
                  if (p[pixel[6]] > cb)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                        if (p[pixel[9]] > cb)
                          if (p[pixel[10]] > cb)
                            if (p[pixel[11]] > cb)
                              if (p[pixel[12]] > cb)
                                if (p[pixel[13]] > cb)
                                  if (p[pixel[14]] > cb)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[4]] < c_b)
                if (p[pixel[5]] > cb)
                  if (p[pixel[10]] > cb)
                    if (p[pixel[6]] > cb)
                      if (p[pixel[7]] > cb)
                        if (p[pixel[8]] > cb)
                          if (p[pixel[9]] > cb)
                            if (p[pixel[11]] > cb)
                              if (p[pixel[12]] > cb)
                                if (p[pixel[13]] > cb)
                                  if (p[pixel[14]] > cb)
                                    if (p[pixel[15]] > cb)
                                    {
                                    }
                                    else
                                      continue;
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[10]] < c_b)
                    if (p[pixel[11]] < c_b)
                      if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                            if (p[pixel[15]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[5]] < c_b)
                  if (p[pixel[6]] < c_b)
                    if (p[pixel[7]] < c_b)
                      if (p[pixel[8]] < c_b)
                        if (p[pixel[9]] < c_b)
                          if (p[pixel[10]] < c_b)
                          {
                          }
                          else if (p[pixel[15]] < c_b)
                          {
                          }
                          else
                            continue;
                        else if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[9]] > cb)
                if (p[pixel[5]] > cb)
                  if (p[pixel[6]] > cb)
                    if (p[pixel[7]] > cb)
                      if (p[pixel[8]] > cb)
                        if (p[pixel[10]] > cb)
                          if (p[pixel[11]] > cb)
                            if (p[pixel[12]] > cb)
                              if (p[pixel[13]] > cb)
                                if (p[pixel[14]] > cb)
                                  if (p[pixel[15]] > cb)
                                  {
                                  }
                                  else
                                    continue;
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else if (p[pixel[9]] < c_b)
                if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[8]] > cb)
              if (p[pixel[5]] > cb)
                if (p[pixel[6]] > cb)
                  if (p[pixel[7]] > cb)
                    if (p[pixel[9]] > cb)
                      if (p[pixel[10]] > cb)
                        if (p[pixel[11]] > cb)
                          if (p[pixel[12]] > cb)
                            if (p[pixel[13]] > cb)
                              if (p[pixel[14]] > cb)
                                if (p[pixel[4]] > cb)
                                {
                                }
                                else if (p[pixel[15]] > cb)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else if (p[pixel[8]] < c_b)
              if (p[pixel[9]] < c_b)
                if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                              if (p[pixel[6]] < c_b)
                                if (p[pixel[7]] < c_b)
                                {
                                }
                                else
                                  continue;
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[7]] > cb)
            if (p[pixel[5]] > cb)
              if (p[pixel[6]] > cb)
                if (p[pixel[8]] > cb)
                  if (p[pixel[9]] > cb)
                    if (p[pixel[10]] > cb)
                      if (p[pixel[11]] > cb)
                        if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                            if (p[pixel[4]] > cb)
                              if (p[pixel[3]] > cb)
                              {
                              }
                              else if (p[pixel[14]] > cb)
                              {
                              }
                              else
                                continue;
                            else if (p[pixel[14]] > cb)
                              if (p[pixel[15]] > cb)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else if (p[pixel[7]] < c_b)
            if (p[pixel[8]] < c_b)
              if (p[pixel[9]] < c_b)
                if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                              if (p[pixel[6]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[3]] < c_b)
                          if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                              if (p[pixel[6]] < c_b)
                              {
                              }
                              else
                                continue;
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[6]] > cb)
          if (p[pixel[5]] > cb)
            if (p[pixel[7]] > cb)
              if (p[pixel[8]] > cb)
                if (p[pixel[9]] > cb)
                  if (p[pixel[10]] > cb)
                    if (p[pixel[11]] > cb)
                      if (p[pixel[12]] > cb)
                        if (p[pixel[4]] > cb)
                          if (p[pixel[3]] > cb)
                            if (p[pixel[2]] > cb)
                            {
                            }
                            else if (p[pixel[13]] > cb)
                            {
                            }
                            else
                              continue;
                          else if (p[pixel[13]] > cb)
                            if (p[pixel[14]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                            if (p[pixel[15]] > cb)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else if (p[pixel[6]] < c_b)
          if (p[pixel[7]] < c_b)
            if (p[pixel[8]] < c_b)
              if (p[pixel[9]] < c_b)
                if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else if (p[pixel[3]] < c_b)
                          if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[2]] < c_b)
                        if (p[pixel[3]] < c_b)
                          if (p[pixel[4]] < c_b)
                            if (p[pixel[5]] < c_b)
                            {
                            }
                            else
                              continue;
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else
          continue;
      else if (p[pixel[5]] > cb)
        if (p[pixel[6]] > cb)
          if (p[pixel[7]] > cb)
            if (p[pixel[8]] > cb)
              if (p[pixel[9]] > cb)
                if (p[pixel[10]] > cb)
                  if (p[pixel[11]] > cb)
                    if (p[pixel[4]] > cb)
                      if (p[pixel[3]] > cb)
                        if (p[pixel[2]] > cb)
                          if (p[pixel[1]] > cb)
                          {
                          }
                          else if (p[pixel[12]] > cb)
                          {
                          }
                          else
                            continue;
                        else if (p[pixel[12]] > cb)
                          if (p[pixel[13]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[12]] > cb)
                        if (p[pixel[13]] > cb)
                          if (p[pixel[14]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[12]] > cb)
                      if (p[pixel[13]] > cb)
                        if (p[pixel[14]] > cb)
                          if (p[pixel[15]] > cb)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else
          continue;
      else if (p[pixel[5]] < c_b)
        if (p[pixel[6]] < c_b)
          if (p[pixel[7]] < c_b)
            if (p[pixel[8]] < c_b)
              if (p[pixel[9]] < c_b)
                if (p[pixel[10]] < c_b)
                  if (p[pixel[11]] < c_b)
                    if (p[pixel[4]] < c_b)
                      if (p[pixel[3]] < c_b)
                        if (p[pixel[2]] < c_b)
                          if (p[pixel[1]] < c_b)
                          {
                          }
                          else if (p[pixel[12]] < c_b)
                          {
                          }
                          else
                            continue;
                        else if (p[pixel[12]] < c_b)
                          if (p[pixel[13]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else if (p[pixel[12]] < c_b)
                        if (p[pixel[13]] < c_b)
                          if (p[pixel[14]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else if (p[pixel[12]] < c_b)
                      if (p[pixel[13]] < c_b)
                        if (p[pixel[14]] < c_b)
                          if (p[pixel[15]] < c_b)
                          {
                          }
                          else
                            continue;
                        else
                          continue;
                      else
                        continue;
                    else
                      continue;
                  else
                    continue;
                else
                  continue;
              else
                continue;
            else
              continue;
          else
            continue;
        else
          continue;
      else
        continue;
      posxy.x = x;
      posxy.y = y;
      posxy.angle = 0;
      ret_corners.push_back(posxy);
      num_corners++;
    }

  *ret_num_corners = num_corners;
  return ret_corners;
}
