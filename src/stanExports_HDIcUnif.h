// Generated by rstantools.  Do not edit by hand.

/*
    rmBayes is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    rmBayes is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with rmBayes.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_HDIcUnif_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_HDIcUnif");
    reader.add_event(37, 35, "end", "model_HDIcUnif");
    return reader;
}
#include <stan_meta_header.hpp>
class model_HDIcUnif
  : public stan::model::model_base_crtp<model_HDIcUnif> {
private:
        int N;
        int C;
        std::vector<vector_d> Y;
        double tcrit;
public:
    model_HDIcUnif(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_HDIcUnif(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_HDIcUnif_namespace::model_HDIcUnif";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 1);
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "C", "int", context__.to_vec());
            C = int(0);
            vals_i__ = context__.vals_i("C");
            pos__ = 0;
            C = vals_i__[pos__++];
            check_greater_or_equal(function__, "C", C, 2);
            current_statement_begin__ = 4;
            validate_non_negative_index("Y", "C", C);
            validate_non_negative_index("Y", "N", N);
            context__.validate_dims("data initialization", "Y", "vector_d", context__.to_vec(N,C));
            Y = std::vector<Eigen::Matrix<double, Eigen::Dynamic, 1> >(N, Eigen::Matrix<double, Eigen::Dynamic, 1>(C));
            vals_r__ = context__.vals_r("Y");
            pos__ = 0;
            size_t Y_j_1_max__ = C;
            size_t Y_k_0_max__ = N;
            for (size_t j_1__ = 0; j_1__ < Y_j_1_max__; ++j_1__) {
                for (size_t k_0__ = 0; k_0__ < Y_k_0_max__; ++k_0__) {
                    Y[k_0__](j_1__) = vals_r__[pos__++];
                }
            }
            current_statement_begin__ = 5;
            context__.validate_dims("data initialization", "tcrit", "double", context__.to_vec());
            tcrit = double(0);
            vals_r__ = context__.vals_r("tcrit");
            pos__ = 0;
            tcrit = vals_r__[pos__++];
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 9;
            validate_non_negative_index("mu", "C", C);
            num_params_r__ += C;
            current_statement_begin__ = 10;
            num_params_r__ += 1;
            current_statement_begin__ = 11;
            num_params_r__ += 1;
            current_statement_begin__ = 12;
            validate_non_negative_index("b", "N", N);
            num_params_r__ += N;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_HDIcUnif() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 9;
        if (!(context__.contains_r("mu")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        validate_non_negative_index("mu", "C", C);
        context__.validate_dims("parameter initialization", "mu", "vector_d", context__.to_vec(C));
        Eigen::Matrix<double, Eigen::Dynamic, 1> mu(C);
        size_t mu_j_1_max__ = C;
        for (size_t j_1__ = 0; j_1__ < mu_j_1_max__; ++j_1__) {
            mu(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(mu);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 10;
        if (!(context__.contains_r("sigma")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigma missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigma");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigma", "double", context__.to_vec());
        double sigma(0);
        sigma = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, sigma);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigma: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 11;
        if (!(context__.contains_r("tau")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable tau missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("tau");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "tau", "double", context__.to_vec());
        double tau(0);
        tau = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, tau);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable tau: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 12;
        if (!(context__.contains_r("b")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable b missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("b");
        pos__ = 0U;
        validate_non_negative_index("b", "N", N);
        context__.validate_dims("parameter initialization", "b", "vector_d", context__.to_vec(N));
        Eigen::Matrix<double, Eigen::Dynamic, 1> b(N);
        size_t b_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < b_j_1_max__; ++j_1__) {
            b(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(b);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable b: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 9;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> mu;
            (void) mu;  // dummy to suppress unused var warning
            if (jacobian__)
                mu = in__.vector_constrain(C, lp__);
            else
                mu = in__.vector_constrain(C);
            current_statement_begin__ = 10;
            local_scalar_t__ sigma;
            (void) sigma;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma = in__.scalar_lb_constrain(0, lp__);
            else
                sigma = in__.scalar_lb_constrain(0);
            current_statement_begin__ = 11;
            local_scalar_t__ tau;
            (void) tau;  // dummy to suppress unused var warning
            if (jacobian__)
                tau = in__.scalar_lb_constrain(0, lp__);
            else
                tau = in__.scalar_lb_constrain(0);
            current_statement_begin__ = 12;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> b;
            (void) b;  // dummy to suppress unused var warning
            if (jacobian__)
                b = in__.vector_constrain(N, lp__);
            else
                b = in__.vector_constrain(N);
            // model body
            current_statement_begin__ = 17;
            for (int i = 1; i <= N; ++i) {
                current_statement_begin__ = 18;
                lp_accum__.add(normal_log<propto__>(get_base1(Y, i, "Y", 1), add(mu, get_base1(b, i, "b", 1)), sigma));
            }
            current_statement_begin__ = 20;
            lp_accum__.add(normal_log<propto__>(b, 0, tau));
            current_statement_begin__ = 24;
            lp_accum__.add((-(2) * stan::math::log(sigma)));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("mu");
        names__.push_back("sigma");
        names__.push_back("tau");
        names__.push_back("b");
        names__.push_back("se");
        names__.push_back("hdi");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(C);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(C);
        dims__.push_back(2);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_HDIcUnif_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> mu = in__.vector_constrain(C);
        size_t mu_j_1_max__ = C;
        for (size_t j_1__ = 0; j_1__ < mu_j_1_max__; ++j_1__) {
            vars__.push_back(mu(j_1__));
        }
        double sigma = in__.scalar_lb_constrain(0);
        vars__.push_back(sigma);
        double tau = in__.scalar_lb_constrain(0);
        vars__.push_back(tau);
        Eigen::Matrix<double, Eigen::Dynamic, 1> b = in__.vector_constrain(N);
        size_t b_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < b_j_1_max__; ++j_1__) {
            vars__.push_back(b(j_1__));
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            if (!include_gqs__ && !include_tparams__) return;
            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 29;
            double se;
            (void) se;  // dummy to suppress unused var warning
            stan::math::initialize(se, DUMMY_VAR__);
            stan::math::fill(se, DUMMY_VAR__);
            current_statement_begin__ = 30;
            validate_non_negative_index("hdi", "C", C);
            validate_non_negative_index("hdi", "2", 2);
            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> hdi(C, 2);
            stan::math::initialize(hdi, DUMMY_VAR__);
            stan::math::fill(hdi, DUMMY_VAR__);
            // generated quantities statements
            current_statement_begin__ = 32;
            stan::math::assign(se, (sigma / stan::math::sqrt(N)));
            current_statement_begin__ = 33;
            stan::model::assign(hdi, 
                        stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list())), 
                        subtract(mu, (tcrit * se)), 
                        "assigning variable hdi");
            current_statement_begin__ = 34;
            stan::model::assign(hdi, 
                        stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list())), 
                        add(mu, (tcrit * se)), 
                        "assigning variable hdi");
            // validate, write generated quantities
            current_statement_begin__ = 29;
            check_greater_or_equal(function__, "se", se, 0);
            vars__.push_back(se);
            current_statement_begin__ = 30;
            size_t hdi_j_2_max__ = 2;
            size_t hdi_j_1_max__ = C;
            for (size_t j_2__ = 0; j_2__ < hdi_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < hdi_j_1_max__; ++j_1__) {
                    vars__.push_back(hdi(j_1__, j_2__));
                }
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_HDIcUnif";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t mu_j_1_max__ = C;
        for (size_t j_1__ = 0; j_1__ < mu_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "tau";
        param_names__.push_back(param_name_stream__.str());
        size_t b_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < b_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "b" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "se";
        param_names__.push_back(param_name_stream__.str());
        size_t hdi_j_2_max__ = 2;
        size_t hdi_j_1_max__ = C;
        for (size_t j_2__ = 0; j_2__ < hdi_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < hdi_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "hdi" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t mu_j_1_max__ = C;
        for (size_t j_1__ = 0; j_1__ < mu_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "tau";
        param_names__.push_back(param_name_stream__.str());
        size_t b_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < b_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "b" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "se";
        param_names__.push_back(param_name_stream__.str());
        size_t hdi_j_2_max__ = 2;
        size_t hdi_j_1_max__ = C;
        for (size_t j_2__ = 0; j_2__ < hdi_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < hdi_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "hdi" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
    }
}; // model
}  // namespace
typedef model_HDIcUnif_namespace::model_HDIcUnif stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif
