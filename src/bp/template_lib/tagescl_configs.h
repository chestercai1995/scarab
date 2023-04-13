/* Copyright 2020 HPS/SAFARI Research Groups
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

struct TAGE_SC_CONFIG_64KB_ffp {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 10;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 20;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};
struct TAGE_SC_L_CONFIG_64KB {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 10;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 20;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


/****************************************************************************************/
struct TAGE_SC_L_CONFIG_80KB {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 18;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 21;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 8;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

/****************************************************************************************/

struct TAGE_SC_L_CONFIG_FUTURE_64KB {
  // static constexpr bool PIPELINE_SUPPORT = true;
  //static constexpr bool USE_LOOP_PREDICTOR       = true;
  //static constexpr bool USE_SC                   = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 10;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 20;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = true;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

struct TAGE_SC_L_CONFIG_REAL_FUTURE_64KB {
  // static constexpr bool PIPELINE_SUPPORT = true;
  //static constexpr bool USE_LOOP_PREDICTOR       = true;
  //static constexpr bool USE_SC                   = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 10;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 20;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = true;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

/****************************************************************************************/
struct TAGE_SC_L_CONFIG_60KB {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 17;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 12;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 16;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = true;
    static constexpr bool USE_REAL_STALE_HIST_PC     = true;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 7;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

/****************************************************************************************/
struct TAGE_SC_L_CONFIG_FUTURE_56KB {
  // static constexpr bool PIPELINE_SUPPORT = true;
  //static constexpr bool USE_LOOP_PREDICTOR       = true;
  //static constexpr bool USE_SC                   = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 17;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 7;
    static constexpr int LONG_HISTORY_TAG_BITS       = 11;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 12;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 16;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = true;
    static constexpr bool USE_REAL_STALE_HIST_PC     = true;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

/****************************************************************************************/
struct TAGE_SC_L_CONFIG_REAL_FUTURE_48KB {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  //static constexpr bool USE_LOOP_PREDICTOR       = true;
  //static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 17;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 7;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 12;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 11;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = true;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


/****************************************************************************************/
struct TAGE_SC_L_CONFIG_FUTURE_40KB {
  // static constexpr bool PIPELINE_SUPPORT = true;
  //static constexpr bool USE_LOOP_PREDICTOR       = true;
  //static constexpr bool USE_SC                   = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 7;
    static constexpr int LONG_HISTORY_TAG_BITS       = 11;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 9;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 19;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 19;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = true;
    static constexpr bool USE_REAL_STALE_HIST_PC     = true;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


/****************************************************************************************/
struct TAGE_SC_L_CONFIG_32KB {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 9;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 12;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 14;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


/****************************************************************************************/
struct TAGE_SC_L_CONFIG_REAL_FUTURE_16KB {
  // static constexpr bool PIPELINE_SUPPORT = true;
  //static constexpr bool USE_LOOP_PREDICTOR       = true;
  //static constexpr bool USE_SC                   = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 4;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 15;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 11;
    static constexpr int FIRST_2WAY_TABLE            = 7;
    static constexpr int LAST_2WAY_TABLE             = 21;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 2;
    static constexpr int LOG_ENTRIES_PER_BANK        = 8;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 11;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 17;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 3;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = true;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 7;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {6, 3};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 7;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 8};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 6;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 7;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = false;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = false;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = false;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


/****************************************************************************************/
struct TAGE_SC_L_CONFIG_REAL_FUTURE_8KB {
  // static constexpr bool PIPELINE_SUPPORT = true;
  //static constexpr bool USE_LOOP_PREDICTOR       = true;
  //static constexpr bool USE_SC                   = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 4;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 15;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 11;
    static constexpr int FIRST_2WAY_TABLE            = 7;
    static constexpr int LAST_2WAY_TABLE             = 21;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 2;
    static constexpr int LOG_ENTRIES_PER_BANK        = 7;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 9;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 17;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 3;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 12;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = true;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 3;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 7;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 7;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {6, 3};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 7;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 8};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 6;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 7;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = false;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = false;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = false;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 7;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

struct TAGE_SC_L_CONFIG_32KB_V2 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 9;
    static constexpr int LONG_HISTORY_TAG_BITS       = 13;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 9;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 16;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 17;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

struct TAGE_SC_L_CONFIG_32KB_V3 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 250;
    static constexpr int NUM_HISTORIES               = 14;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 10;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 9;
    static constexpr int LONG_HISTORY_TAG_BITS       = 13;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 9;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 16;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 17;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

struct TAGE_SC_L_CONFIG_32KB_V4 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 7;
    static constexpr int LONG_HISTORY_TAG_BITS       = 10;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 10;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 10;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

struct TAGE_SC_L_CONFIG_32KB_V5 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 250;
    static constexpr int NUM_HISTORIES               = 9;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 7;
    static constexpr int FIRST_2WAY_TABLE            = 5;
    static constexpr int LAST_2WAY_TABLE             = 9;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 9;
    static constexpr int LONG_HISTORY_TAG_BITS       = 14;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 9;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 16;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 17;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_16KB_V2 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 8;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 18;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 18;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

struct TAGE_SC_L_CONFIG_16KB_V3 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 6;
    static constexpr int LONG_HISTORY_TAG_BITS       = 11;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 9;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 10;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 10;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_16KB_V4 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 250;
    static constexpr int NUM_HISTORIES               = 9;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 9;
    static constexpr int FIRST_2WAY_TABLE            = 6;
    static constexpr int LAST_2WAY_TABLE             = 12;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 6;
    static constexpr int LONG_HISTORY_TAG_BITS       = 11;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 9;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 10;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 10;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_16KB_V5 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 250;
    static constexpr int NUM_HISTORIES               = 9;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 9;
    static constexpr int FIRST_2WAY_TABLE            = 6;
    static constexpr int LAST_2WAY_TABLE             = 12;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 8;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 18;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 18;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_80KB_V2 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 19;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 22;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 14;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 8;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

struct TAGE_SC_L_CONFIG_80KB_V3 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 19;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 19;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 14;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 10;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 11;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 10;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 8;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_80KB_V4 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 9;
    static constexpr int LONG_HISTORY_TAG_BITS       = 13;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 18;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 20;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 14;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 8;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_80KB_V5 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 24;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 18;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 6;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 14;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 8;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};



struct TAGE_SC_L_CONFIG_FUTURE_96KB_V1 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  //static constexpr bool USE_LOOP_PREDICTOR       = true;
  //static constexpr bool USE_SC                   = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 11;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 10;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 15;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = true;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

struct TAGE_SC_L_CONFIG_96KB_V2 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 12;
    static constexpr int LONG_HISTORY_TAG_BITS       = 20;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 13;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 21;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_96KB_V3 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 10;
    static constexpr int LONG_HISTORY_TAG_BITS       = 14;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 20;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 22;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 10;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 11;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 10;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 8;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_96KB_V4 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 10;
    static constexpr int LONG_HISTORY_TAG_BITS       = 14;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 16;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 16;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 12;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 12;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 12;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 8;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_FUTURE_128KB_V1 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  //static constexpr bool USE_LOOP_PREDICTOR       = true;
  //static constexpr bool USE_SC                   = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 9;
    static constexpr int LONG_HISTORY_TAG_BITS       = 14;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 11;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 10;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 20;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = true;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_128KB_V2 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 12;
    static constexpr int LONG_HISTORY_TAG_BITS       = 20;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 10;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 19;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 28;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_128KB_V3 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 8;
    static constexpr int LONG_HISTORY_TAG_BITS       = 12;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 11;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 10;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 20;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 11;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 11;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 11;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 8;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_FUTURE_192KB_V1 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  //static constexpr bool USE_LOOP_PREDICTOR       = true;
  //static constexpr bool USE_SC                   = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 10;
    static constexpr int LONG_HISTORY_TAG_BITS       = 16;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 11;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 19;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 24;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = true;
    static constexpr bool USE_REAL_STALE_HIST_PC     = true;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

struct TAGE_SC_L_CONFIG_192KB_V2 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 12;
    static constexpr int LONG_HISTORY_TAG_BITS       = 20;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 11;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 16;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 19;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 16;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};

struct TAGE_SC_L_CONFIG_192KB_V3 {
  // static constexpr bool PIPELINE_SUPPORT = true;
  static constexpr bool USE_LOOP_PREDICTOR       = true;
  static constexpr bool USE_SC                   = true;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 10;
    static constexpr int LONG_HISTORY_TAG_BITS       = 16;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 11;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 16;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 19;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 14;
    static constexpr bool USE_STALE_HIST_PC          = false;
    static constexpr bool USE_REAL_STALE_HIST_PC     = false;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 12;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 12;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 12;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 10;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};


struct TAGE_SC_L_CONFIG_FUTURE_192KB_WITH_64K_PER_BANK {
  // static constexpr bool PIPELINE_SUPPORT = true;
  //static constexpr bool USE_LOOP_PREDICTOR       = true;
  //static constexpr bool USE_SC                   = true;
  static constexpr bool USE_LOOP_PREDICTOR       = false;
  static constexpr bool USE_SC                   = false;
  static constexpr int  CONFIDENCE_COUNTER_WIDTH = 7;

  struct TAGE {
    static constexpr int MIN_HISTORY_SIZE            = 6;
    static constexpr int MAX_HISTORY_SIZE            = 3000;
    static constexpr int NUM_HISTORIES               = 18;
    static constexpr int PATH_HISTORY_WIDTH          = 27;
    static constexpr int FIRST_LONG_HISTORY_TABLE    = 13;
    static constexpr int FIRST_2WAY_TABLE            = 9;
    static constexpr int LAST_2WAY_TABLE             = 22;
    static constexpr int SHORT_HISTORY_TAG_BITS      = 10;
    static constexpr int LONG_HISTORY_TAG_BITS       = 16;
    static constexpr int PRED_COUNTER_WIDTH          = 3;
    static constexpr int USEFUL_BITS                 = 1;
    static constexpr int LOG_ENTRIES_PER_BANK        = 16;
    static constexpr int SHORT_HISTORY_NUM_BANKS     = 19;
    static constexpr int LONG_HISTORY_NUM_BANKS      = 24;
    static constexpr int EXTRA_ENTRIES_TO_ALLOCATE   = 1;
    static constexpr int TICKS_UNTIL_USEFUL_SHIFT    = 1024;
    static constexpr int ALT_SELECTOR_LOG_TABLE_SIZE = 4;
    static constexpr int ALT_SELECTOR_ENTRY_WIDTH    = 5;
    static constexpr int BIMODAL_HYSTERESIS_SHIFT    = 2;
    static constexpr int BIMODAL_LOG_TABLES_SIZE     = 13;
    static constexpr bool USE_STALE_HIST_PC          = true;
    static constexpr bool USE_REAL_STALE_HIST_PC     = true;
  };

  struct LOOP {
    static constexpr int LOG_NUM_ENTRIES         = 5;
    static constexpr int ITERATION_COUNTER_WIDTH = 10;
    static constexpr int TAG_BITS                = 10;
    static constexpr int CONFIDENCE_THRESHOLD    = 15;
  };

  struct SC {
    static constexpr int UPDATE_THRESHOLD_WIDTH       = 12;
    static constexpr int PERPC_UPDATE_THRESHOLD_WIDTH = 8;
    static constexpr int INITIAL_UPDATE_THRESHOLD     = 35 << 3;

    static constexpr bool USE_VARIABLE_THRESHOLD = true;
    static constexpr int  LOG_SIZE_PERPC_THRESHOLD_TABLE =
      USE_VARIABLE_THRESHOLD ? 6 : 0;
    static constexpr int LOG_SIZE_VARIABLE_THRESHOLD_TABLE =
      LOG_SIZE_PERPC_THRESHOLD_TABLE / 2;
    static constexpr int VARIABLE_THRESHOLD_WIDTH            = 6;
    static constexpr int INITIAL_VARIABLE_THRESHOLD          = 7;
    static constexpr int INITIAL_VARIABLE_THRESHOLD_FOR_BIAS = 4;
    static constexpr int LOG_BIAS_ENTRIES                    = 8;

    static constexpr int LOG_SIZE_GLOBAL_HISTORY_GEHL = 10;
    struct GLOBAL_HISTORY_GEHL_HISTORIES {
      static constexpr int arr[] = {40, 24, 10};
    };
    static constexpr int LOG_SIZE_PATH_GEHL = 9;
    struct PATH_GEHL_HISTORIES {
      static constexpr int arr[] = {25, 16, 9};
    };

    static constexpr bool USE_LOCAL_HISTORY                  = true;
    static constexpr int  FIRST_LOCAL_HISTORY_LOG_TABLE_SIZE = 8;
    static constexpr int  FIRST_LOCAL_HISTORY_SHIFT          = 2;
    static constexpr int  LOG_SIZE_FIRST_LOCAL_GEHL          = 10;
    struct FIRST_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {11, 6, 3};
    };

    static constexpr bool USE_SECOND_LOCAL_HISTORY            = true;
    static constexpr int  SECOND_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  SECOND_LOCAL_HISTORY_SHIFT          = 5;
    static constexpr int  LOG_SIZE_SECOND_LOCAL_GEHL          = 9;
    struct SECOND_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {16, 11, 6};
    };

    static constexpr bool USE_THIRD_LOCAL_HISTORY            = true;
    static constexpr int  THIRD_LOCAL_HISTORY_LOG_TABLE_SIZE = 4;
    static constexpr int  THIRD_LOCAL_HISTORY_SHIFT          = 10;
    static constexpr int  LOG_SIZE_THIRD_LOCAL_GEHL          = 10;
    struct THIRD_LOCAL_GEHL_HISTORIES {
      static constexpr int arr[] = {9, 4};
    };

    static constexpr bool USE_IMLI                 = true;
    static constexpr bool USE_IMLI_HISTORIES       = true;
    static constexpr int  IMLI_COUNTER_WIDTH       = 8;
    static constexpr int  IMLI_TABLE_SIZE          = 1 << IMLI_COUNTER_WIDTH;
    static constexpr int  log_size_first_imli_gehl = 8;
    struct FIRST_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {IMLI_COUNTER_WIDTH};
    };
    static constexpr int LOG_SIZE_SECOND_IMLI_GEHL = 9;
    struct SECOND_IMLI_GEHL_HISTORIES {
      static constexpr int arr[] = {10, 4};
    };

    static constexpr int PRECISION             = 6;
    static constexpr int SC_PATH_HISTORY_WIDTH = 27;
  };
};
