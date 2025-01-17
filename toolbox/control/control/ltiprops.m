function ltiprops(type)
%LTIPROPS  Help on LTI model properties.
%
%   LTIPROPS gives details on the generic properties of LTI models.
%
%   LTIPROPS(MODELTYPE) gives details on the properties specific
%   to the various types of LTI models.  The string MODELTYPE 
%   selects the model type among the following:
%      'tf'  :   transfer functions (TF objects)
%      'zpk' :   zero-pole-gain models (ZPK objects)
%      'ss'  :   state-space models (SS objects)
%      'frd' :   frequency response data (FRD objects).
%
%   Note that you can type
%      ltiprops tf
%   as a shorthand for
%      ltiprops('tf') .
%
%   See also LTIMODELS, SET, GET.

%	 Author: P. Gahinet 5-21-96
%	 Copyright 1986-2002 The MathWorks, Inc. 
%   $Revision: 1.18.4.1 $  $Date: 2003/01/07 19:32:51 $

if nargin==0,
   type = 'lti';
elseif ~ischar(type)
   error('MODELTYPE must be a string.')
end

switch lower(type(1:min(3,end)))
case 'lti'
   % Generic LTI properties
   DisplayStr = {...
         ' Help on properties of LTI models.'...
         ' '...
         ' LTI properties are divided into two categories:' ...
         '   * Generic properties shared by all LTI model types'...
         '   * Properties specific to TF, ZPK, SS, or FRD models.  For details,'...
         '     type LTIPROPS followed by TF, ZPK, SS, or FRD.'...
         '  '...
         ' For an LTI model with Ny outputs and Nu inputs, the generic LTI properties'...
         ' include:'...
         ' '...
         ' Ts           - Sample time (in seconds).'...
         '                Assignable values:'...
         '                  * Positive scalar (sampling period) for discrete models.'...
         '                  * -1 for discrete models with unspecified sampling rate.'...
         '                  * 0 for continuous models.'...
         '                Default value:  0.'...
         '  '...
         ' InputDelay   - Input delays (transport delays in the input channels).'...
         '                Content:  Nu-by-1 vector of time delays for each input.'...
         '                Assignable values:'...
         '                  * Vector of length Nu'...
         '                  * Scalar -> same delay for each input'...
         '                  * Specify time delays'...
         '                     - in seconds for continuous-time models'...
         '                     - as integers for discrete-time models (integer value k'...
         '                       means a delay of k sampling periods).'...
         '                Default value:  0.'...
         '  '...
         ' OutputDelay  - Output delays (transport delays in the output channels).'...
         '                Content:  Ny-by-1 vector of time delays for each output.'...
         '                Assignable values:'...
         '                  * Vector of length Ny'...
         '                  * Scalar -> same delay for each output'...
         '                Default value:  0.'...
         '  '...
         ' ioDelay      - I/O delays (transport delays between inputs and outputs).'...
         '                Content:  Ny-by-Nu matrix DM where DM(i,j) specifies the time'...
         '                          delay between input j and output i.'...
         '                Assignable values:'...
         '                  * Ny-by-Nu array -> independent delays for each I/O pair'...
         '                  * Scalar -> same delay for all I/O pairs'...
         '                Default value:  0.'...
         '                Note: Use DELAY2Z to map discrete-time delays to poles at z=0.'...
         '  '...
         ' InputName    - Input channel names.'...
         '                Content:  Nu-by-1 cell array of strings.'...
         '                Assignable values:'...
         '                  * String for single-input models, e.g., ''torque'''...
         '                  * Cell vector of strings for multiple-input models,'...
         '                    e.g., {''thrust'' ; ''aileron deflection''}'...
         '                  * Use '''' for unnamed input channels.'...
         '                Default names:  '''' (empty string) for all channels.'...
         '  '...
         ' OutputName   - Output channel names.'...
         '                Content:  Ny-by-1 cell array of strings.'...
         '                Assignable/default values:  Same as for InputName.'...
         '  '...
         ' InputGroup   - Groups of input channels.'...
         '                Content:  Structure where the field names are group names'...
         '                   and the field values are the input channels belonging to'...
         '                   each group.'...
         '                Assignable values:  See Contents.'...
         '                Example:  sys.InputGroup.controls = [1 2]'...
         '                          sys.InputGroup.noise = [3 5]'...
         '                Default value:  struct with no field.'...
         '  '...
         ' OutputGroup  - Groups of output channels.'...
         '                Content:  Structure where the field names are group names'...
         '                   and the field values are the output channels belonging to'...
         '                   each group.'...
         '  '...
         ' Notes        - User''s notes.'...
         '                Content:  Any string or cell array of strings.'...
         '                Example:  ''This model was created on Jan. 1st, 2000'''...
         '  '...
         ' Userdata     - Additional information or data.'...
         '                Content:  Any MATLAB data type.'...
         ' '...
         ' Use SET and GET to set and access property values, as in'...
         '    set(sys,''inputname'',''u'')'...
         '    get(sys,''iodelay'')'...
         };
   
   
case 'tf'
   % TF-specific properties
   DisplayStr = {...
         ' Help on properties of transfer function (TF) models.'...
         ' '...
         ' In addition to the generic LTI properties (type "ltiprops" for details),'...
         ' all TF models share the following TF-specific properties, listed here for'...
         ' a model with Ny outputs and Nu inputs:'...
         ' '...
         ' num       - Numerator data.'...
         '             Content:  Ny-by-Nu cell array of row vectors for single TF'...
         '                       model.  Cell array of size [Ny Nu S1 ... Sp] for'...
         '                       S1-by-...-Sp arrays of TF models.'...
         '             Assignable values:'...
         '               * Row vector for SISO models'...
         '               * Cell array of row vectors for MIMO models'...
         '               * ND cell array of row vectors for TF arrays'...
         '             Example:  {[1 0]  1 ; 3  [1 2 3]}.'...
         ' '...
         ' den       - Denominator data.'...
         '             Content:  Same as for NUM property.'...
         '             Assignable values:  See NUM property.'...
         ' '...
         ' Variable  - Variable name (string).'...
         '             Assignable values:  ''s'', ''p'', ''z'', ''z^-1'', or ''q''.'...
         '             Default values:  ''s'' (continuous) and ''z'' (discrete).'...
         '             Note:  The variable name influences the display and allows'...
         '                    for DSP-oriented specification of discrete TFs.'...
         };
   
case 'zpk'
   % ZPK-specific properties
   DisplayStr = {...
         ' Help on properties of zero-pole-gain (ZPK) models.'...
         ' '...
         ' In addition to the generic LTI properties (type "ltiprops" for details),'...
         ' all ZPK models share the following ZPK-specific properties, listed here'...
         ' for a model with Ny outputs and Nu inputs:'...
         ' '...
         ' z        - Zeros (for each channel).'...
         '            Content:  Ny-by-Nu cell array of column vectors for single'...
         '                      ZPK model.  Cell array of size [Ny Nu S1 ... Sp]'...
         '                      for S1-by-...-Sp arrays of ZPK models.'...
         '            Assignable values:'...
         '              * Vector for SISO models'...
         '              * Cell array of vectors for MIMO models or ZPK arrays'...
         '              * Use [] for channels w/o zeros.'...
         '            Example:  {[1 0]  1 ; 3  [1 2 3]}.'...
         '  '...
         ' p        - Poles (for each channel).'...
         '            Content:  Same as for Z property.'...
         '            Assignable values:  See Z property.'...
         '  '...
         ' k        - Gains (for each channel).'...
         '            Content/Assignable values:'...
         '              * Ny-by-Nu matrix for single ZPK model'...
         '              * ND array of size [Ny Nu S1 ... Sp] for S1-by-...-Sp arrays'...
         '                of ZPK models.'...
         ' '...
         ' Variable - Variable name (string).'...
         '            Assignable values:  ''s'', ''p'', ''z'', ''z^-1'', or ''q''.'...
         '            Default values:  ''s'' (continuous) and ''z'' (discrete).'...
         '            Note:  The variable name influences the display and z^-1 allows'...
         '                   for DSP-oriented specification of discrete ZPK models.'...
         };   
   
case 'ss'
   % SS-specific properties
   DisplayStr = {...
         ' Help on properties of state-space (SS) models.'...
         ' '...
         ' In addition to the generic LTI properties (type "ltiprops" for details),'...
         ' all SS models share the following SS-specific properties, listed here'...
         ' for a model with Ny outputs, Nu inputs, and Nx states:'...
         ' '...
         ' a         - State matrix.'...
         '             Content/Assignable values:'...
         '               * Nx-by-Nx matrix for single SS model'...
         '               * Array of size [Nx Nx S1 ... Sp] for S1-by-...-Sp'...
         '                 arrays of SS models.'...
         '  '...
         ' b         - Input-to-state matrix.'...
         '             Content/Assignable values:'...
         '               * Nx-by-Nu matrix for single SS model'...
         '               * Array of size [Nx Nu S1 ... Sp] for S1-by-...-Sp'...
         '                 arrays of SS models.'...
         '  '...
         ' c         - State-to-output matrix.'...
         '             Content/Assignable values:'...
         '               * Ny-by-Nx matrix for single SS model'...
         '               * Array of size [Ny Nx S1 ... Sp] for S1-by-...-Sp'...
         '                 arrays of SS models.'...
         '  '...
         ' d         - Feedthrough matrix.'...
         '             Content/Assignable values:'...
         '               * Ny-by-Nu matrix for single SS model'...
         '               * Array of size [Ny Nu S1 ... Sp] for S1-by-...-Sp'...
         '                 arrays of SS models.'...
         '               * 0 to mean the zero matrix of appropriate dimensions.'...
         '  '...
         ' e         - E matrix for models in descriptor form.'...
         '             Content/Assignable values:'...
         '               * Nx-by-Nx matrix for single SS model'...
         '               * Array of size [Nx Nx S1 ... Sp] for S1-by-...-Sp'...
         '                 arrays of SS models.'...
         '               * [] to mean the identity matrix of size Nx.'...
         '             Default value:  [].'...
         '  '...
         ' StateName - State names.'...
         '             Content:  Nx-by-1 cell array of strings.'...
         '             Assignable values:'...
         '               * String for first-order models, e.g., ''position'''...
         '               * Cell vector of strings for models with two or more'...
         '                 states, e.g., {''position'' ; ''velocity''}'...
         '               * Use '''' for unnamed states.'...
         '             Default names:  '''' (empty string) for all states.'...
         };   
   
case 'frd'
   % FRD-specific properties
   DisplayStr = {...
         ' Help on properties of frequency response data (FRD) models.'...
         ' '...
         ' In addition to the generic LTI properties (type "ltiprops" for details),'...
         ' all FRD models share the following FRD-specific properties, listed here'...
         ' for a model with Ny outputs, Nu inputs, and Nw frequency points:'...
         ' '...
         ' Frequency    - Vector of frequencies.'...
         '                Content/Assignable values:  Vector of Nw real numbers.'...
         ' '...
         ' ResponseData - Complex frequency response data.'...
         '                Content/Assignable values:'...
         '                  * ND array of size [Ny Nu Nw] for a single FRD model'...
         '                  * Array of size [Ny Nu Nw S1 ... Sp] for S1-by-...-Sp'...
         '                    arrays of FRD models.'...
         ' '...
         ' Units        - Frequency units (string).'...
         '                Content/Assignable values:  ''rad/s'' or ''Hz'''...
         '                Default value:  ''rad/s''.'...
         };   
   
otherwise
   error(sprintf('Unknown model type ''%s''.',type))
   
end

disp(' ')
disp(char(DisplayStr))

